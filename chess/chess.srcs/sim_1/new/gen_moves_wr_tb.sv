//==============================================
// timescale
//==============================================
`timescale 1ns / 1ps

//==============================================
// gen_moves_wr_tb
//==============================================
module gen_moves_wr_tb;

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
    gen_moves_wr uut
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
        UNIT = 64'h00_00_00_00_00_00_00_01;
        i = 6'h0;
        WHITE_UNITS = 64'h00_00_00_00_00_00_00_01;
        EMPTY = 64'hff_ff_ff_ff_ff_ff_ff_fe;
        #10;
        assert (MOVES == 64'h01_01_01_01_01_01_01_fe) $display("1. passed!");
        else $display("1. failed.");
        
        // TEST 2    
        UNIT = 64'h00_00_00_00_08_00_00_00;
        i = 6'h1b;
        WHITE_UNITS = 64'h00_00_00_00_08_00_00_00;
        EMPTY = 64'hff_ff_ff_ff_f7_ff_ff_ff;
        #10;
        assert (MOVES == 64'h08_08_08_08_f7_08_08_08) $display("2. passed!");
        else $display("2. failed.");
        
        // TEST 3
        UNIT = 64'h00_00_20_00_00_00_00_00;
        i = 6'h2d;
        WHITE_UNITS = 64'h00_00_64_00_00_00_00_00;
        EMPTY = 64'hdf_ff_9b_ff_ff_ff_df_ff;
        #10;
        assert (MOVES == 64'h20_20_18_20_20_20_20_00) $display("3. passed!");
        else $display("3. failed.");
  
        $finish;
    end
    
endmodule
