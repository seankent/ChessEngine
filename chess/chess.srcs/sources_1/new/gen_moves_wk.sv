//==============================================
// gen_moves_wk
//==============================================
module gen_moves_wk(
    input logic clk,
    input logic rst,
    input logic [10:0] state,
    input logic [63:0] UNIT,
    input logic [63:0] WHITE_UNITS,
    input logic [63:0] EMPTY,
    input logic [63:0] WR,
    input logic [63:0] BLACK_ATTACKS,
    output logic [63:0] MOVES
    );
    
    //==============================
    // parameters
    //==============================
    parameter FILE_A = 64'h01_01_01_01_01_01_01_01;     // a-file
    parameter FILE_H = 64'h80_80_80_80_80_80_80_80;     // h-file
    
    //==============================
    // logic
    //==============================
    logic [63:0] MOVES_comb;
    logic [63:0] MOVE0, MOVE1, MOVE2, MOVE3, MOVE4, MOVE5, MOVE6, MOVE7;
    logic [63:0] KINGSIDE_CASTLE;
    logic [63:0] QUEENSIDE_CASTLE;
    
    //==============================
    // always_comb
    //==============================
    always_comb begin
        MOVE0 = (UNIT << 1) & ~FILE_A;      // move right
        MOVE1 = (UNIT << 9) & ~FILE_A;      // move up and right
        MOVE2 = UNIT << 8;                  // move up
        MOVE3 = (UNIT << 7) & ~FILE_H;      // move up and left
        MOVE4 = (UNIT >> 1) & ~FILE_H;      // move left
        MOVE5 = (UNIT >> 9) & ~FILE_H;      // move down and left
        MOVE6 = UNIT >> 8;                  // move down
        MOVE7 = (UNIT >> 7) & ~FILE_A;      // move down and right
        if (state[1] & UNIT[4] & WR[7] & (EMPTY[6:5] == 2'b11) & (BLACK_ATTACKS[6:4] == 3'b000)) KINGSIDE_CASTLE = 64'h00_00_00_00_00_00_00_40;     // kingside castle (allowed)
        else KINGSIDE_CASTLE = 64'h0;       // kingside castle (not allowed)
        if (state[2] & UNIT[4] & WR[0] & (EMPTY[3:1] == 3'b111) & (BLACK_ATTACKS[4:1] == 3'b000)) QUEENSIDE_CASTLE = 64'h00_00_00_00_00_00_00_04;   // queenside castle (allowed)
        else QUEENSIDE_CASTLE = 64'h0;      // queenside castle (not allowed)
        MOVES_comb = (MOVE0 | MOVE1 | MOVE2 | MOVE3 | MOVE4 | MOVE5 | MOVE6 | MOVE7 | KINGSIDE_CASTLE | QUEENSIDE_CASTLE) & ~WHITE_UNITS;
    end
    
    //==============================
    // always_ff
    //==============================
    always_ff @(posedge clk) begin
        if (rst) MOVES <= 64'b0;
        else MOVES <= MOVES_comb;
    end

endmodule

