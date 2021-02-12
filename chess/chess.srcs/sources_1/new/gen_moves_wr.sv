//==============================================
// gen_moves_wr
//==============================================
module gen_moves_wr(
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
    parameter [63:0] FILES [7:0] = {FILE_H, FILE_G, FILE_F, FILE_E, FILE_D, FILE_C, FILE_B, FILE_A};
    parameter [63:0] RANKS [7:0] = {RANK_8, RANK_7, RANK_6, RANK_5, RANK_4, RANK_3, RANK_2, RANK_1};
    
    //==============================
    // logic
    //==============================
    logic [63:0] MOVES_comb;
    logic [63:0] MOVES_RANK, MOVES_FILE;
    logic [63:0] FILE, RANK;
    logic [63:0] TEMP0, TEMP1, TEMP2, TEMP3, TEMP4; 
    
    //==============================
    // always_comb
    //==============================
    always_comb begin
        RANK = RANKS[i >> 3];                                           // get rank mask
        FILE = FILES[i[2:0]];                                           // get file mask
        TEMP0 = {<<{UNIT}};
        TEMP1 = {<<{~EMPTY & RANK}};
        TEMP2 = {<<{~EMPTY & FILE}};
        TEMP3 = {<<{TEMP1 - (TEMP0 << 1)}};
        TEMP4 = {<<{TEMP2 - (TEMP0 << 1)}}; 
        MOVES_RANK = (((~EMPTY & RANK) - (UNIT << 1)) ^ TEMP3) & RANK;  // rank moves
        MOVES_FILE = (((~EMPTY & FILE) - (UNIT << 1)) ^ TEMP4) & FILE;  // file moves
        MOVES_comb = (MOVES_RANK | MOVES_FILE) & ~WHITE_UNITS;
    end
    
    //==============================
    // always_ff
    //==============================
    always_ff @(posedge clk) begin
        if (rst) MOVES <= 64'b0;
        else MOVES <= MOVES_comb;
    end

endmodule
