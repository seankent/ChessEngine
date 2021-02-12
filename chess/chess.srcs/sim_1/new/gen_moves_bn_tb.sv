//==============================================
// timescale
//==============================================
`timescale 1ns / 1ps

//==============================================
// gen_moves_bn_tb
//==============================================
module gen_moves_bn_tb;

    //==============================
    // logic
    //==============================
    logic clk;
    logic rst;
    logic [63:0] UNIT;
    logic [63:0] BLACK_UNITS;
    logic [63:0] MOVES;
    
    //==============================
    // uut
    //==============================
    gen_moves_bn uut
    (
        .clk(clk),
        .rst(rst),
        .UNIT(UNIT),
        .BLACK_UNITS(BLACK_UNITS),
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
        BLACK_UNITS = 64'h00_00_00_00_00_00_00_00;
        
        // RESET
        #10;
        rst = 1'b1;
        #10;
        rst = 1'b0;
        #10;
        
        // TEST 1
        UNIT = 64'h02_00_00_00_00_00_00_00;
        BLACK_UNITS = 64'h02_00_00_00_00_00_00_00;
        #10;
        assert (MOVES == 64'h00_08_05_00_00_00_00_00) $display("1. passed!");
        else $display("1. failed.");
        
        // TEST 2
        UNIT = 64'h00_00_00_00_08_00_00_00;
        BLACK_UNITS = 64'h00_00_00_00_08_00_00_00;
        #10;
        assert (MOVES == 64'h00_00_14_22_00_22_14_00) $display("2. passed!");
        else $display("2. failed.");
        
        // TEST 3
        UNIT = 64'h00_00_00_00_10_00_00_00;
        BLACK_UNITS = 64'h00_00_00_00_10_00_00_00;
        #10;
        assert (MOVES == 64'h00_00_28_44_00_44_28_00) $display("3. passed!");
        else $display("3. failed.");
        
        // TEST 4
        UNIT = 64'h00_00_02_00_00_00_00_00;
        BLACK_UNITS = 64'h00_00_02_00_00_00_00_00;
        #10;
        assert (MOVES == 64'h05_08_00_08_05_00_00_00) $display("4. passed!");
        else $display("4. failed.");
        
        // TEST 5
        UNIT = 64'h00_00_00_00_01_00_00_00;
        BLACK_UNITS = 64'h00_00_00_00_01_00_00_00;
        #10;
        assert (MOVES == 64'h00_00_02_04_00_04_02_00) $display("5. passed!");
        else $display("5. failed.");
        
        // TEST 6
        UNIT = 64'h00_00_00_00_00_80_00_00;
        BLACK_UNITS = 64'h00_00_00_00_00_80_00_00;
        #10;
        assert (MOVES == 64'h00_00_00_40_20_00_20_40) $display("6. passed!");
        else $display("6. failed.");
        
        // TEST 7
        UNIT = 64'h00_00_00_00_08_00_00_00;
        BLACK_UNITS = 64'h00_00_10_02_08_02_10_00;
        #10;
        assert (MOVES == 64'h00_00_04_20_00_20_04_00) $display("7. passed!");
        else $display("7. failed.");
  
        $finish;
    end
    
endmodule
