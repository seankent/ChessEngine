//==============================================
// gen_moves_wb
//==============================================
module gen_moves_wb(
    input logic clk,
    input logic rst,
    input logic [63:0] UNIT,
    input logic [5:0] i,
    input logic [63:0] WHITE_UNITS,
    input logic [63:0] EMPTY,
    output logic [63:0] MOVES
    );
    
    //==============================
    // parameters
    //==============================
    parameter DIAGONAL_A8A8 = 64'h01_00_00_00_00_00_00_00;      // a8-a8 diagonal
    parameter DIAGONAL_A7B8 = 64'h02_01_00_00_00_00_00_00;      // a7-b8 diagonal
    parameter DIAGONAL_A6C8 = 64'h04_02_01_00_00_00_00_00;      // a6-c8 diagonal
    parameter DIAGONAL_A5D8 = 64'h08_04_02_01_00_00_00_00;      // a5-d8 diagonal
    parameter DIAGONAL_A4E8 = 64'h10_08_04_02_01_00_00_00;      // a4-e8 diagonal
    parameter DIAGONAL_A3F8 = 64'h20_10_08_04_02_01_00_00;      // a3-f8 diagonal
    parameter DIAGONAL_A2G8 = 64'h40_20_10_08_04_02_01_00;      // a2-g8 diagonal
    parameter DIAGONAL_A1H8 = 64'h80_40_20_10_08_04_02_01;      // a1-h8 diagonal
    parameter DIAGONAL_B1H7 = 64'h00_80_40_20_10_08_04_02;      // b1-h8 diagonal
    parameter DIAGONAL_C1H6 = 64'h00_00_80_40_20_10_08_04;      // c1-h8 diagonal
    parameter DIAGONAL_D1H5 = 64'h00_00_00_80_40_20_10_08;      // d1-h8 diagonal
    parameter DIAGONAL_E1H4 = 64'h00_00_00_00_80_40_20_10;      // e1-h8 diagonal
    parameter DIAGONAL_F1H3 = 64'h00_00_00_00_00_80_40_20;      // f1-h8 diagonal
    parameter DIAGONAL_G1H2 = 64'h00_00_00_00_00_00_80_40;      // g1-h8 diagonal
    parameter DIAGONAL_H1H1 = 64'h00_00_00_00_00_00_00_80;      // h1-h8 diagonal
    parameter DIAGONAL_A1A1 = 64'h00_00_00_00_00_00_00_01;      // a1-a1 diagonal
    parameter DIAGONAL_A2B1 = 64'h00_00_00_00_00_00_01_02;      // a2-b1 diagonal
    parameter DIAGONAL_A3C1 = 64'h00_00_00_00_00_01_02_04;      // a3-c1 diagonal
    parameter DIAGONAL_A4D1 = 64'h00_00_00_00_01_02_04_08;      // a4-d1 diagonal
    parameter DIAGONAL_A5E1 = 64'h00_00_00_01_02_04_08_10;      // a5-e1 diagonal
    parameter DIAGONAL_A6F1 = 64'h00_00_01_02_04_08_10_20;      // a6-f1 diagonal
    parameter DIAGONAL_A7G1 = 64'h00_01_02_04_08_10_20_40;      // a7-g1 diagonal
    parameter DIAGONAL_A8H1 = 64'h01_02_04_08_10_20_40_80;      // a8-h1 diagonal
    parameter DIAGONAL_B8H2 = 64'h02_04_08_10_20_40_80_00;      // b8-h2 diagonal
    parameter DIAGONAL_C8H3 = 64'h0_408_10_20_40_80_00_00;      // c8-h3 diagonal
    parameter DIAGONAL_D8H4 = 64'h08_10_20_40_80_00_00_00;      // d8-h4 diagonal
    parameter DIAGONAL_E8H5 = 64'h10_20_40_80_00_00_00_00;      // e8-h5 diagonal
    parameter DIAGONAL_F8H6 = 64'h20_40_80_00_00_00_00_00;      // f8-h6 diagonal
    parameter DIAGONAL_G8H7 = 64'h40_80_00_00_00_00_00_00;      // g8-h7 diagonal
    parameter DIAGONAL_H8H8 = 64'h80_00_00_00_00_00_00_00;      // h8-h8 diagonal
    parameter [63:0] DIAGONALS_UP [14:0] = {DIAGONAL_H1H1, DIAGONAL_G1H2, DIAGONAL_F1H3, DIAGONAL_E1H4, DIAGONAL_D1H5, DIAGONAL_C1H6, DIAGONAL_B1H7, DIAGONAL_A1H8, DIAGONAL_A2G8, DIAGONAL_A3F8, DIAGONAL_A4E8, DIAGONAL_A5D8, DIAGONAL_A6C8, DIAGONAL_A7B8, DIAGONAL_A8A8};
    parameter [63:0] DIAGONALS_DOWN [14:0] = {DIAGONAL_H8H8, DIAGONAL_G8H7, DIAGONAL_F8H6, DIAGONAL_E8H5, DIAGONAL_D8H4, DIAGONAL_C8H3, DIAGONAL_B8H2, DIAGONAL_A8H1, DIAGONAL_A7G1, DIAGONAL_A6F1, DIAGONAL_A5E1, DIAGONAL_A4D1, DIAGONAL_A3C1, DIAGONAL_A2B1, DIAGONAL_A1A1};
    
    //==============================
    // logic
    //==============================
    logic [63:0] MOVES_comb;
    logic [63:0] MOVES_DIAGONAL_UP, MOVES_DIAGONAL_DOWN;
    logic [63:0] DIAGONAL_UP, DIAGONAL_DOWN;
    logic [63:0] TEMP0, TEMP1, TEMP2, TEMP3, TEMP4; 
    
    //==============================
    // always_comb
    //==============================
    always_comb begin
        DIAGONAL_UP = DIAGONALS_UP[6'd7 - (i >> 3) + i[2:0]];       // get mask for the upper right diagonal
        DIAGONAL_DOWN = DIAGONALS_DOWN[(i >> 3) + i[2:0]];          // get mask for the downward right diagonal
        TEMP0 = {<<{UNIT}};
        TEMP1 = {<<{~EMPTY & DIAGONAL_UP}};
        TEMP2 = {<<{~EMPTY & DIAGONAL_DOWN}};
        TEMP3 = {<<{TEMP1 - (TEMP0 << 1)}};
        TEMP4 = {<<{TEMP2 - (TEMP0 << 1)}}; 
        MOVES_DIAGONAL_UP = (((~EMPTY & DIAGONAL_UP) - (UNIT << 1)) ^ TEMP3) & DIAGONAL_UP;         // moves along the upper right diagonal
        MOVES_DIAGONAL_DOWN = (((~EMPTY & DIAGONAL_DOWN) - (UNIT << 1)) ^ TEMP4) & DIAGONAL_DOWN;   // move along the downward right diagonal
        MOVES_comb = (MOVES_DIAGONAL_UP | MOVES_DIAGONAL_DOWN) & ~WHITE_UNITS;
    end
    
    //==============================
    // always_ff
    //==============================
    always_ff @(posedge clk) begin
        if (rst) MOVES <= 64'b0;
        else MOVES <= MOVES_comb;
    end

endmodule
