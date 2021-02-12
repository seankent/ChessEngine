//==============================================
// timescale
//==============================================
`timescale 1ns / 1ps

//==============================================
// gen_moves_wk_tb
//==============================================
module gen_moves_wk_tb;

    //==============================
    // logic
    //==============================
    logic clk;
    logic rst;
    logic [10:0] state;
    logic [63:0] UNIT;
    logic [63:0] WHITE_UNITS;
    logic [63:0] EMPTY;
    logic [63:0] WR;
    logic [63:0] BLACK_ATTACKS;
    logic [63:0] MOVES;
    
    //==============================
    // uut
    //==============================
    gen_moves_wk uut
    (
        .clk(clk),
        .rst(rst),
        .state(state),
        .UNIT(UNIT),
        .WHITE_UNITS(WHITE_UNITS),
        .EMPTY(EMPTY),
        .WR(WR),
        .BLACK_ATTACKS(BLACK_ATTACKS),
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
        WHITE_UNITS = 64'h00_00_00_00_00_00_00_00;
        EMPTY = 64'h00_00_00_00_00_00_00_00;
        BLACK_ATTACKS = 64'h00_00_00_00_00_00_00_00;
        WR = 64'h00_00_00_00_00_00_00_00;
        
        // RESET
        #10;
        rst = 1'b1;
        #10;
        rst = 1'b0;
        #10;
        
        // TEST 1
        UNIT = 64'h00_00_00_00_00_00_00_10;
        WHITE_UNITS = 64'h00_00_00_00_00_00_00_10;
        EMPTY = 64'hff_ff_ff_ff_ff_ff_ff_ef;
        WR = 64'h00_00_00_00_00_00_00_00;
        BLACK_ATTACKS = 64'h00_00_00_00_00_00_00_00;
        #10;
        assert (MOVES == 64'h00_00_00_00_00_00_38_28) $display("1. passed!");
        else $display("1. failed.");
        
        // TEST 2
        UNIT = 64'h00_00_00_00_10_00_00_00;
        WHITE_UNITS = 64'h00_00_00_00_10_00_00_00;
        EMPTY = 64'hff_ff_ff_ff_ef_ff_ff_ff;
        WR = 64'h00_00_00_00_00_00_00_00;
        BLACK_ATTACKS = 64'h00_00_00_00_00_00_00_00;
        #10;
        assert (MOVES == 64'h00_00_00_38_28_38_00_00) $display("2. passed!");
        else $display("2. failed.");
        
        // TEST 3
        UNIT = 64'h00_00_04_00_00_00_00_00;
        WHITE_UNITS = 64'h00_04_0e_04_00_00_00_00;
        EMPTY = 64'hff_f1_f1_f1_ff_ff_ff_ff;
        WR = 64'h00_04_00_00_00_00_00_00;
        BLACK_ATTACKS = 64'h5e_f5_1e_20_5c_a7_41_80;
        #10;
        assert (MOVES == 64'h00_0a_00_0a_00_00_00_00) $display("3. passed!");
        else $display("3. failed.");
        
        // TEST 4
        UNIT = 64'h00_00_00_00_00_00_00_10;
        WHITE_UNITS = 64'h00_00_00_00_00_00_00_90;
        EMPTY = 64'hff_ff_ff_ff_ff_ff_ff_6f;
        WR = 64'h00_00_00_00_00_00_00_80;
        BLACK_ATTACKS = 64'h00_00_00_00_00_00_00_00;
        #10;
        assert (MOVES == 64'h00_00_00_00_00_00_38_68) $display("4. passed!");
        else $display("4. failed.");
        
        // TEST 5
        UNIT = 64'h00_00_00_00_00_00_00_10;
        WHITE_UNITS = 64'h00_00_00_00_00_00_00_11;
        EMPTY = 64'hff_ff_ff_ff_ff_ff_ff_ee;
        WR = 64'h00_00_00_00_00_00_00_01;
        BLACK_ATTACKS = 64'h00_00_00_00_00_00_00_00;
        #10;
        assert (MOVES == 64'h00_00_00_00_00_00_38_2c) $display("5. passed!");
        else $display("5. failed.");
        
        // TEST 6
        UNIT = 64'h00_00_00_00_00_00_00_10;
        WHITE_UNITS = 64'h00_00_00_00_00_00_00_91;
        EMPTY = 64'hff_ff_ff_ff_ff_fe_ff_6e;
        WR = 64'h00_00_00_00_00_00_00_81;
        BLACK_ATTACKS = 64'h20_10_08_04_02_00_02_04;
        #10;
        assert (MOVES == 64'h00_00_00_00_00_00_38_68) $display("6. passed!");
        else $display("6. failed.");
        
        // TEST 7
        UNIT = 64'h00_00_00_00_00_00_00_10;
        WHITE_UNITS = 64'h00_00_00_00_00_00_00_d1;
        EMPTY = 64'hff_ff_ff_ff_ff_ff_ff_2e;
        WR = 64'h00_00_00_00_00_00_00_81;
        BLACK_ATTACKS = 64'h00_00_00_00_00_00_00_00;
        #10;
        assert (MOVES == 64'h00_00_00_00_00_00_38_2c) $display("7. passed!");
        else $display("7. failed.");
        
        // TEST 8
        UNIT = 64'h00_00_00_00_00_00_00_10;
        WHITE_UNITS = 64'h00_00_00_00_00_00_00_91;
        EMPTY = 64'hff_ff_ff_ff_ff_ff_bf_6e;
        WR = 64'h00_00_00_00_00_00_00_81;
        BLACK_ATTACKS = 64'h00_00_00_00_00_00_00_a0;
        #10;
        assert (MOVES == 64'h00_00_00_00_00_00_38_2c) $display("8. passed!");
        else $display("8. failed.");
  
        $finish;
    end
    
endmodule
