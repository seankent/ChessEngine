//==============================================
// timescale
//==============================================
`timescale 1ns / 1ps

//==============================================
// gen_moves_wb_tb
//==============================================
module gen_moves_wb_tb;

    //==============================
    // logic
    //==============================
    logic clk;
    logic rst;
    logic [63:0] UNIT;
    logic [5:0] i;
    logic [63:0] WHITE_UNITS;
    logic [63:0] EMPTY;
    logic [63:0] MOVES;
    
    //==============================
    // uut
    //==============================
    gen_moves_wb uut
    (
        .clk(clk),
        .rst(rst),
        .UNIT(UNIT),
        .i(i),
        .WHITE_UNITS(WHITE_UNITS),
        .EMPTY(EMPTY),
        .MOVES(MOVES)
    );
    
    //==============================
    // clk
    //==============================
    always #5 clk = !clk;
    
    //==============================
    // initial
    //==============================
    initial begin
        $display("Running Simulation...");
        clk = 1'b0;
        rst = 1'b0;
        UNIT = 64'h00_00_00_00_00_00_00_00;
        i = 6'h0;
        WHITE_UNITS = 64'h00_00_00_00_00_00_00_00;
        EMPTY = 64'h00_00_00_00_00_00_00_00;
        
        // RESET
        #10;
        rst = 1'b1;
        #10;
        rst = 1'b0;
        #10;
        
        // TEST 1
        UNIT = 64'h00_00_00_00_00_00_00_04;
        i = 6'h2;
        WHITE_UNITS = 64'h00_00_00_00_00_00_00_04;
        EMPTY = 64'hff_ff_ff_ff_ff_ff_ff_fb;
        #10;
        assert (MOVES == 64'h00_00_80_40_20_11_0a_00) $display("1. passed!");
        else $display("1. failed.");
        
        // TEST 2    
        UNIT = 64'h00_00_00_00_08_00_00_00;
        i = 6'h1b;
        WHITE_UNITS = 64'h00_00_00_00_08_00_00_00;
        EMPTY = 64'hff_ff_ff_ff_f7_ff_ff_ff;
        #10;
        assert (MOVES == 64'h80_41_22_14_00_14_22_41) $display("2. passed!");
        else $display("2. failed.");
        
        // TEST 3
        UNIT = 64'h00_00_00_20_00_00_00_00;
        i = 6'h25;
        WHITE_UNITS = 64'h04_00_00_20_40_00_00_00;
        EMPTY = 64'hfb_7f_ff_df_bf_ff_fb_ff;
        #10;
        assert (MOVES == 64'h00_88_50_00_10_08_04_00) $display("3. passed!");
        else $display("3. failed.");
  
        $finish;
    end
    
endmodule
