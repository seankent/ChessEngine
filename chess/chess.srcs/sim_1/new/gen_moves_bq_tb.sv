//==============================================
// timescale
//==============================================
`timescale 1ns / 1ps

//==============================================
// gen_moves_bq_tb
//==============================================
module gen_moves_bq_tb;

    //==============================
    // logic
    //==============================
    logic clk;
    logic rst;
    logic [63:0] UNIT;
    logic [5:0] i;
    logic [63:0] BLACK_UNITS;
    logic [63:0] EMPTY;
    logic [63:0] MOVES;
    
    //==============================
    // uut
    //==============================
    gen_moves_bq uut
    (
        .clk(clk),
        .rst(rst),
        .UNIT(UNIT),
        .i(i),
        .BLACK_UNITS(BLACK_UNITS),
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
        BLACK_UNITS = 64'h00_00_00_00_00_00_00_00;
        EMPTY = 64'h00_00_00_00_00_00_00_00;
        
        // RESET
        #10;
        rst = 1'b1;
        #10;
        rst = 1'b0;
        #10;
        
        // TEST 1
        UNIT = 64'h08_00_00_00_00_00_00_00;
        i = 6'h3b;
        BLACK_UNITS = 64'h08_00_00_00_00_00_00_00;
        EMPTY = 64'hf7_ff_ff_ff_ff_ff_ff_ff;
        #10;
        assert (MOVES == 64'hf7_1c_2a_49_88_08_08_08) $display("1. passed!");
        else $display("1. failed.");
        
        // TEST 2    
        UNIT = 64'h00_00_00_08_00_00_00_00;
        i = 6'h23;
        BLACK_UNITS = 64'h00_00_00_08_00_00_00_00;
        EMPTY = 64'hff_ff_ff_f7_ff_ff_ff_ff;
        #10;
        assert (MOVES == 64'h49_2a_1c_f7_1c_2a_49_88) $display("2. passed!");
        else $display("2. failed.");
        
        // TEST 3
        UNIT = 64'h00_00_00_00_00_40_00_00;
        i = 6'h16;
        BLACK_UNITS = 64'h00_00_00_00_00_c0_00_00;
        EMPTY = 64'hff_ff_f7_ff_ff_3d_ff_ef;
        #10;
        assert (MOVES == 64'h40_40_48_50_e0_3e_e0_50) $display("3. passed!");
        else $display("3. failed.");
  
        $finish;
    end
    
endmodule
