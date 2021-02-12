//==============================================
// timescale
//==============================================
`timescale 1ns / 1ps

//==============================================
// gen_moves_wp_tb
//==============================================
module gen_moves_wp_tb;

    //==============================
    // logic
    //==============================
    logic clk;
    logic rst;
    logic [10:0] state;
    logic [63:0] UNIT;
    logic [63:0] BLACK_UNITS;
    logic [63:0] EMPTY;
    logic [63:0] MOVES;
    
    //==============================
    // uut
    //==============================
    gen_moves_wp uut
    (
        .clk(clk),
        .rst(rst),
        .state(state),
        .UNIT(UNIT),
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
        state = 11'b00_1000_1111_1;
        UNIT = 64'h00_00_00_00_00_00_00_00;
        BLACK_UNITS = 64'h00_00_00_00_00_00_00_00;
        EMPTY = 64'h00_00_00_00_00_00_00_00;
        
        // RESET
        #10;
        rst = 1'b1;
        #10;
        rst = 1'b0;
        #10;
        
        // TEST 1
        UNIT = 64'h00_00_00_00_00_00_08_00;
        BLACK_UNITS = 64'h00_00_00_00_00_00_00_00;
        EMPTY = 64'hff_ff_ff_ff_ff_ff_f7_ff;
        #10;
        assert (MOVES == 64'h00_00_00_00_08_08_00_00) $display("1. passed!");
        else $display("1. failed.");
        
        // TEST 2
        UNIT = 64'h00_00_00_00_00_08_00_00;
        BLACK_UNITS = 64'h00_00_00_10_00_00_00_00;
        EMPTY = 64'hff_ff_ff_ff_ff_f7_ff_ff;
        #10;
        assert (MOVES == 64'h00_00_00_00_08_00_00_00) $display("2. passed!");
        else $display("2. failed.");
        
        // TEST 3
        UNIT = 64'h00_00_00_00_00_00_01_00;
        BLACK_UNITS = 64'h00_00_00_00_00_82_00_00;
        EMPTY = 64'hff_ff_ff_ff_ff_7d_fe_ff;
        #10;
        assert (MOVES == 64'h00_00_00_00_01_03_00_00) $display("3. passed!");
        else $display("3. failed.");
        
        // TEST 4
        UNIT = 64'h00_00_00_00_00_80_00_00;
        BLACK_UNITS = 64'h00_00_00_00_c1_00_00_00;
        EMPTY = 64'hff_ff_ff_ff_3e_7f_ff_ff;
        #10;
        assert (MOVES == 64'h00_00_00_00_40_00_00_00) $display("4. passed!");
        else $display("4. failed.");
        
        // TEST 5
        UNIT = 64'h00_00_00_02_00_00_00_00;
        BLACK_UNITS = 64'h00_00_00_04_00_00_00_00;
        EMPTY = 64'hff_ff_ff_f9_ff_ff_ff_ff;
        state = 11'b00_0010_1111_1;
        #10;
        assert (MOVES == 64'h00_00_06_00_00_00_00_00) $display("5. passed!");
        else $display("5. failed.");
        
        // TEST 6
        UNIT = 64'h00_00_00_04_00_00_00_00;
        BLACK_UNITS = 64'h00_00_00_02_00_00_00_00;
        EMPTY = 64'hff_ff_ff_f9_ff_ff_ff_ff;
        state = 11'b00_0001_1111_1;
        #10;
        assert (MOVES == 64'h00_00_06_00_00_00_00_00) $display("6. passed!");
        else $display("6. failed.");
  
        $finish;
    end
    
endmodule