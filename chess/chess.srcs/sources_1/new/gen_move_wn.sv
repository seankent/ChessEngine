//==============================================
// gen_move_wn
//==============================================
module gen_move_wn(
    input logic clk,
    input logic rst,
    input logic [63:0] UNIT,
    input logic [63:0] WHITE_UNITS,
    output logic [63:0] MOVES
    );
    
    //==============================
    // parameters
    //==============================
    parameter FILE_A = 64'h01_01_01_01_01_01_01_01;     // a-file mask
    parameter FILE_B = 64'h02_02_02_02_02_02_02_02;     // b-file mask
    parameter FILE_G = 64'h40_40_40_40_40_40_40_40;     // g-file mask
    parameter FILE_H = 64'h80_80_80_80_80_80_80_80;     // h-file mask
    
    //==============================
    // always_ff
    //==============================
    always_ff @(posedge clk) begin
        if (rst) MOVES <= 64'b0;
        else MOVES <= ((UNIT << 10) & ~WHITE_UNITS & ~FILE_A & ~FILE_B) |
                      ((UNIT << 17) & ~WHITE_UNITS & ~FILE_A) |
                      ((UNIT << 15) & ~WHITE_UNITS & ~FILE_H) |
                      ((UNIT << 6) & ~WHITE_UNITS & ~FILE_G & ~FILE_H) |
                      ((UNIT >> 10) & ~WHITE_UNITS & ~FILE_G & ~FILE_H) |
                      ((UNIT >> 17) & ~WHITE_UNITS & ~FILE_H) |
                      ((UNIT >> 15) & ~WHITE_UNITS & ~FILE_A) |
                      ((UNIT >> 6) & ~WHITE_UNITS & ~FILE_A & ~FILE_B);
    end

endmodule
