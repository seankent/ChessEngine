//==============================================
// gen_moves_bn
//==============================================
module gen_moves_bn(
    input logic clk,
    input logic rst,
    input logic [63:0] UNIT,
    input logic [63:0] BLACK_UNITS,
    output logic [63:0] MOVES
    );
    
    //==============================
    // parameters
    //==============================
    parameter FILE_A = 64'h01_01_01_01_01_01_01_01;     // a-file
    parameter FILE_B = 64'h02_02_02_02_02_02_02_02;     // b-file
    parameter FILE_G = 64'h40_40_40_40_40_40_40_40;     // g-file
    parameter FILE_H = 64'h80_80_80_80_80_80_80_80;     // h-file
    
    //==============================
    // logic
    //==============================
    logic [63:0] MOVES_comb;
    logic [63:0] MOVE0, MOVE1, MOVE2, MOVE3, MOVE4, MOVE5, MOVE6, MOVE7;
    
    //==============================
    // always_comb
    //==============================
    always_comb begin
        MOVE0 = (UNIT << 10) & ~FILE_A & ~FILE_B;   // move up 1, right 2
        MOVE1 = (UNIT << 17) & ~FILE_A;             // move up 2, right 1
        MOVE2 = (UNIT << 15) & ~FILE_H;             // move up 2, left 1
        MOVE3 = (UNIT << 6) & ~FILE_G & ~FILE_H;    // move up 1, left 2
        MOVE4 = (UNIT >> 10) & ~FILE_G & ~FILE_H;   // move down 1, left 2
        MOVE5 = (UNIT >> 17) & ~FILE_H;             // move down 2, left 1
        MOVE6 = (UNIT >> 15) & ~FILE_A;             // move down 2, right 1
        MOVE7 = (UNIT >> 6) & ~FILE_A & ~FILE_B;    // move down 1, right 2
        MOVES_comb = (MOVE0 | MOVE1 | MOVE2 | MOVE3 | MOVE4 | MOVE5 | MOVE6 | MOVE7) & ~BLACK_UNITS;
    end
    
    //==============================
    // always_ff
    //==============================
    always_ff @(posedge clk) begin
        if (rst) MOVES <= 64'b0;
        else MOVES <= MOVES_comb;
    end

endmodule