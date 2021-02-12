//==============================================
// gen_moves_bp
//==============================================
module gen_moves_bp(
    input logic clk,
    input logic rst,
    input logic [10:0] state,
    input logic [63:0] UNIT,
    input logic [63:0] WHITE_UNITS,
    input logic [63:0] EMPTY,
    output logic [63:0] MOVES
    );
    
    //==============================
    // parameters
    //==============================
    parameter FILE_A = 64'h01_01_01_01_01_01_01_01;     // a-file
    parameter FILE_B = 64'h02_02_02_02_02_02_02_02;     // b-file
    parameter FILE_C = 64'h04_04_04_04_04_04_04_04;     // c-file
    parameter FILE_D = 64'h08_08_08_08_08_08_08_08;     // d-file
    parameter FILE_E = 64'h10_10_10_10_10_10_10_10;     // e-file
    parameter FILE_F = 64'h20_20_20_20_20_20_20_20;     // f-file
    parameter FILE_G = 64'h40_40_40_40_40_40_40_40;     // g-file
    parameter FILE_H = 64'h80_80_80_80_80_80_80_80;     // h-file
    parameter RANK_1 = 64'h00_00_00_00_00_00_00_ff;     // 1st rank
    parameter RANK_2 = 64'h00_00_00_00_00_00_ff_00;     // 2nd rank
    parameter RANK_3 = 64'h00_00_00_00_00_ff_00_00;     // 3rd rank
    parameter RANK_4 = 64'h00_00_00_00_ff_00_00_00;     // 4th rank
    parameter RANK_5 = 64'h00_00_00_ff_00_00_00_00;     // 5th rank
    parameter RANK_6 = 64'h00_00_ff_00_00_00_00_00;     // 6th rank
    parameter RANK_7 = 64'h00_ff_00_00_00_00_00_00;     // 7th rank
    parameter RANK_8 = 64'hff_00_00_00_00_00_00_00;     // 8th rank
    
    //==============================
    // logic
    //==============================
    logic [63:0] MOVES_comb;
    logic [63:0] MOVE_FORWARD_1, MOVE_FORWARD_2, MOVE_RIGHT, MOVE_LEFT;
    logic [63:0] FILE_EP;
    
    //==============================
    // always_comb
    //==============================
    always_comb begin
        case (state[8:5])
            4'd0: FILE_EP = FILE_A;
            4'd1: FILE_EP = FILE_B;
            4'd2: FILE_EP = FILE_C;
            4'd3: FILE_EP = FILE_D;
            4'd4: FILE_EP = FILE_E;
            4'd5: FILE_EP = FILE_F;
            4'd6: FILE_EP = FILE_G;
            4'd7: FILE_EP = FILE_H;
            default: FILE_EP = 64'b0;
        endcase
        MOVE_FORWARD_1 = (UNIT >> 8) & EMPTY;                                       // move forward 1
        MOVE_FORWARD_2 = (UNIT >> 16) & EMPTY & (EMPTY >> 8) & RANK_5;              // move forward 2
        MOVE_RIGHT = (UNIT >> 7) & (WHITE_UNITS | (FILE_EP & RANK_3)) & ~FILE_A;    // move right (including en passant)
        MOVE_LEFT = (UNIT >> 9) & (WHITE_UNITS | (FILE_EP & RANK_3)) & ~FILE_H;     // move left (including en passant)
        MOVES_comb = MOVE_FORWARD_1 | MOVE_FORWARD_2 | MOVE_RIGHT | MOVE_LEFT;
    end
    
    //==============================
    // always_ff
    //==============================
    always_ff @(posedge clk) begin
        if (rst) MOVES <= 64'b0;
        else MOVES <= MOVES_comb;
    end

endmodule