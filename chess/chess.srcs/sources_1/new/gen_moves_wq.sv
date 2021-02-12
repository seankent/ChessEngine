//==============================================
// gen_moves_wq
//==============================================
module gen_moves_wq(
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
    parameter FILE_A = 64'h01_01_01_01_01_01_01_01;             // a-file
    parameter FILE_B = 64'h02_02_02_02_02_02_02_02;             // b-file
    parameter FILE_C = 64'h04_04_04_04_04_04_04_04;             // c-file
    parameter FILE_D = 64'h08_08_08_08_08_08_08_08;             // d-file
    parameter FILE_E = 64'h10_10_10_10_10_10_10_10;             // e-file
    parameter FILE_F = 64'h20_20_20_20_20_20_20_20;             // f-file
    parameter FILE_G = 64'h40_40_40_40_40_40_40_40;             // g-file
    parameter FILE_H = 64'h80_80_80_80_80_80_80_80;             // h-file
    parameter RANK_1 = 64'h00_00_00_00_00_00_00_ff;             // 1st rank
    parameter RANK_2 = 64'h00_00_00_00_00_00_ff_00;             // 2nd rank
    parameter RANK_3 = 64'h00_00_00_00_00_ff_00_00;             // 3rd rank
    parameter RANK_4 = 64'h00_00_00_00_ff_00_00_00;             // 4th rank
    parameter RANK_5 = 64'h00_00_00_ff_00_00_00_00;             // 5th rank
    parameter RANK_6 = 64'h00_00_ff_00_00_00_00_00;             // 6th rank
    parameter RANK_7 = 64'h00_ff_00_00_00_00_00_00;             // 7th rank
    parameter RANK_8 = 64'hff_00_00_00_00_00_00_00;             // 8th rank
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
    parameter [63:0] FILES [7:0] = {FILE_H, FILE_G, FILE_F, FILE_E, FILE_D, FILE_C, FILE_B, FILE_A};
    parameter [63:0] RANKS [7:0] = {RANK_8, RANK_7, RANK_6, RANK_5, RANK_4, RANK_3, RANK_2, RANK_1};
    parameter [63:0] DIAGONALS_UP [14:0] = {DIAGONAL_H1H1, DIAGONAL_G1H2, DIAGONAL_F1H3, DIAGONAL_E1H4, DIAGONAL_D1H5, DIAGONAL_C1H6, DIAGONAL_B1H7, DIAGONAL_A1H8, DIAGONAL_A2G8, DIAGONAL_A3F8, DIAGONAL_A4E8, DIAGONAL_A5D8, DIAGONAL_A6C8, DIAGONAL_A7B8, DIAGONAL_A8A8};
    parameter [63:0] DIAGONALS_DOWN [14:0] = {DIAGONAL_H8H8, DIAGONAL_G8H7, DIAGONAL_F8H6, DIAGONAL_E8H5, DIAGONAL_D8H4, DIAGONAL_C8H3, DIAGONAL_B8H2, DIAGONAL_A8H1, DIAGONAL_A7G1, DIAGONAL_A6F1, DIAGONAL_A5E1, DIAGONAL_A4D1, DIAGONAL_A3C1, DIAGONAL_A2B1, DIAGONAL_A1A1};
    
    //==============================
    // logic
    //==============================
    logic [63:0] MOVES_comb;
    logic [63:0] MOVES_RANK, MOVES_FILE, MOVES_DIAGONAL_UP, MOVES_DIAGONAL_DOWN;
    logic [63:0] RANK, FILE, DIAGONAL_UP, DIAGONAL_DOWN;
    logic [63:0] TEMP0, TEMP1, TEMP2, TEMP3, TEMP4, TEMP5, TEMP6, TEMP7, TEMP8; 
    
    //==============================
    // always_comb
    //==============================
    always_comb begin
        RANK = RANKS[i >> 3];                                           // get rank mask
        FILE = FILES[i[2:0]];                                           // get file mask
        DIAGONAL_UP = DIAGONALS_UP[6'd7 - (i >> 3) + i[2:0]];           // get mask for the upper right diagonal
        DIAGONAL_DOWN = DIAGONALS_DOWN[(i >> 3) + i[2:0]];              // get mask for the downward right diagonal
        TEMP0 = {<<{UNIT}};
        TEMP1 = {<<{~EMPTY & RANK}};
        TEMP2 = {<<{~EMPTY & FILE}};
        TEMP3 = {<<{TEMP1 - (TEMP0 << 1)}};
        TEMP4 = {<<{TEMP2 - (TEMP0 << 1)}}; 
        TEMP5 = {<<{~EMPTY & DIAGONAL_UP}};
        TEMP6 = {<<{~EMPTY & DIAGONAL_DOWN}};
        TEMP7 = {<<{TEMP5 - (TEMP0 << 1)}};
        TEMP8 = {<<{TEMP6 - (TEMP0 << 1)}};
        MOVES_RANK = (((~EMPTY & RANK) - (UNIT << 1)) ^ TEMP3) & RANK;                              // rank moves
        MOVES_FILE = (((~EMPTY & FILE) - (UNIT << 1)) ^ TEMP4) & FILE;                              // file moves 
        MOVES_DIAGONAL_UP = (((~EMPTY & DIAGONAL_UP) - (UNIT << 1)) ^ TEMP7) & DIAGONAL_UP;         // moves along the upper right diagonal
        MOVES_DIAGONAL_DOWN = (((~EMPTY & DIAGONAL_DOWN) - (UNIT << 1)) ^ TEMP8) & DIAGONAL_DOWN;   // move along the downward right diagonal
        MOVES_comb = (MOVES_RANK | MOVES_FILE | MOVES_DIAGONAL_UP | MOVES_DIAGONAL_DOWN) & ~WHITE_UNITS;
    end
    
    //==============================
    // always_ff
    //==============================
    always_ff @(posedge clk) begin
        if (rst) MOVES <= 64'b0;
        else MOVES <= MOVES_comb;
    end

endmodule
