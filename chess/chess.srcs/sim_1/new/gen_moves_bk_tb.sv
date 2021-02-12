//==============================================
// timescale
//==============================================
`timescale 1ns / 1ps

//==============================================
// gen_moves_bk_tb
//==============================================
module gen_moves_bk_tb;

    //==============================
    // logic
    //==============================
    logic clk;
    logic rst;
    logic [10:0] state;
    logic [63:0] UNIT;
    logic [63:0] BLACK_UNITS;
    logic [63:0] EMPTY;
    logic [63:0] BR;
    logic [63:0] WHITE_ATTACKS;
    logic [63:0] MOVES;
    
    //==============================
    // uut
    //==============================
    gen_moves_bk uut
    (
        .clk(clk),
        .rst(rst),
        .state(state),
        .UNIT(UNIT),
        .BLACK_UNITS(BLACK_UNITS),
        .EMPTY(EMPTY),
        .BR(BR),
        .WHITE_ATTACKS(WHITE_ATTACKS),
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
        state = 11'b00_1000_1111_0;
        UNIT = 64'h00_00_00_00_00_00_00_00;
        BLACK_UNITS = 64'h00_00_00_00_00_00_00_00;
        EMPTY = 64'h00_00_00_00_00_00_00_00;
        WHITE_ATTACKS = 64'h00_00_00_00_00_00_00_00;
        BR = 64'h00_00_00_00_00_00_00_00;
        
        // RESET
        #10;
        rst = 1'b1;
        #10;
        rst = 1'b0;
        #10;
        
        // TEST 1
        UNIT = 64'h10_00_00_00_00_00_00_00;
        BLACK_UNITS = 64'h10_00_00_00_00_00_00_00;
        EMPTY = 64'hef_ff_ff_ff_ff_ff_ff_ff;
        BR = 64'h00_00_00_00_00_00_00_00;
        WHITE_ATTACKS = 64'h00_00_00_00_00_00_00_00;
        #10;
        assert (MOVES == 64'h28_38_00_00_00_00_00_00) $display("1. passed!");
        else $display("1. failed.");
        
        // TEST 2
        UNIT = 64'h00_00_00_10_00_00_00_00;
        BLACK_UNITS = 64'h00_00_00_10_00_00_00_00;
        EMPTY = 64'hff_ff_ff_ef_ff_ff_ff_ff;
        BR = 64'h00_00_00_00_00_00_00_00;
        WHITE_ATTACKS = 64'h00_00_00_00_00_00_00_00;
        #10;
        assert (MOVES == 64'h00_00_38_28_38_00_00_00) $display("2. passed!");
        else $display("2. failed.");
        
        // TEST 3
        UNIT = 64'h00_00_04_00_00_00_00_00;
        BLACK_UNITS = 64'h00_0a_04_0a_00_00_00_00;
        EMPTY = 64'hff_f1_f1_f1_ff_ff_ff_ff;
        BR = 64'h00_02_00_00_00_00_00_00;
        WHITE_ATTACKS = 64'h25_1a_f4_18_2f_51_a0_40;
        #10;
        assert (MOVES == 64'h00_04_0a_04_00_00_00_00) $display("3. passed!");
        else $display("3. failed.");
        
        // TEST 4
        UNIT = 64'h10_00_00_00_00_00_00_00;
        BLACK_UNITS = 64'h91_00_00_00_00_00_00_00;
        EMPTY = 64'h6e_ff_ff_ff_ff_ff_ff_ff;
        BR = 64'h81_00_00_00_00_00_00_00;
        WHITE_ATTACKS = 64'h00_00_00_00_00_00_00_00;
        #10;
        assert (MOVES == 64'h6c_38_00_00_00_00_00_00) $display("4. passed!");
        else $display("4. failed.");
        
        // TEST 5
        UNIT = 64'h10_00_00_00_00_00_00_00;
        BLACK_UNITS = 64'h91_00_00_00_00_00_00_00;
        EMPTY = 64'h6e_ff_ff_ff_ff_ff_ff_ef;
        BR = 64'h81_00_00_00_00_00_00_00;
        WHITE_ATTACKS = 64'h10_10_10_11_92_54_38_ef;
        #10;
        assert (MOVES == 64'h28_38_00_00_00_00_00_00) $display("5. passed!");
        else $display("5. failed.");
        
        // TEST 6
        UNIT = 64'h10_00_00_00_00_00_00_00;
        BLACK_UNITS = 64'h91_00_00_00_00_00_00_00;
        EMPTY = 64'h6e_fb_ff_ff_ff_ff_ff_ff;
        BR = 64'h81_00_00_00_00_00_00_00;
        WHITE_ATTACKS = 64'h0a_00_00_00_00_00_00_00;
        #10;
        assert (MOVES == 64'h68_38_00_00_00_00_00_00) $display("6. passed!");
        else $display("6. failed.");
  
        $finish;
    end
    
endmodule
