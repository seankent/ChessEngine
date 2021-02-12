//==============================================
// timescale
//==============================================
`timescale 1ns / 1ps

//==============================================
// gen_moves_bp_tb
//==============================================
module gen_moves_bp_tb;

    //==============================
    // logic
    //==============================
    logic clk;
    logic rst;
    logic [10:0] state;
    logic [63:0] UNIT;
    logic [63:0] WHITE_UNITS;
    logic [63:0] EMPTY;
    logic [63:0] MOVES;
    
    //==============================
    // uut
    //==============================
    gen_moves_bp uut
    (
        .clk(clk),
        .rst(rst),
        .state(state),
        .UNIT(UNIT),
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
        state = 11'b00_1000_1111_0;
        UNIT = 64'h00_00_00_00_00_00_00_00;
        WHITE_UNITS = 64'h00_00_00_00_00_00_00_00;
        EMPTY = 64'h00_00_00_00_00_00_00_00;
        
        // RESET
        #10;
        rst = 1'b1;
        #10;
        rst = 1'b0;
        #10;
        
        // TEST 1
        UNIT = 64'h00_20_00_00_00_00_00_00;
        WHITE_UNITS = 64'h00_00_00_00_00_00_00_00;
        EMPTY = 64'hff_df_ff_ff_ff_ff_ff_ff;
        #10;
        assert (MOVES == 64'h00_00_20_20_00_00_00_00) $display("1. passed!");
        else $display("1. failed.");
        
        // TEST 2
        UNIT = 64'h00_20_00_00_00_00_00_00;
        WHITE_UNITS = 64'h00_00_20_00_00_00_00_00;
        EMPTY = 64'hff_df_df_ff_ff_ff_ff_ff;
        #10;
        assert (MOVES == 64'h00_00_00_00_00_00_00_00) $display("2. passed!");
        else $display("2. failed.");
        
        // TEST 3
        UNIT = 64'h00_00_00_00_00_01_00_00;
        WHITE_UNITS = 64'h00_00_00_00_00_00_80_00;
        EMPTY = 64'hff_ff_ff_ff_ff_fe_7f_ff;
        #10;
        assert (MOVES == 64'h00_00_00_00_00_00_01_00) $display("3. passed!");
        else $display("3. failed.");
        
        // TEST 4
        UNIT = 64'h00_00_00_00_01_00_00_00;
        WHITE_UNITS = 64'h00_00_00_00_02_80_00_00;
        EMPTY = 64'hff_ff_ff_ff_fc_7f_ff_ff;
        state = 11'b00_0001_1111_0;
        #10;
        assert (MOVES == 64'h00_00_00_00_00_03_00_00) $display("4. passed!");
        else $display("4. failed.");
        
        // TEST 5
        UNIT = 64'h00_00_00_00_80_00_00_00;
        WHITE_UNITS = 64'h00_00_00_00_40_81_00_00;
        EMPTY = 64'hff_ff_ff_ff_3f_7e_ff_ff;
        state = 11'b00_0110_1111_0;
        #10;
        assert (MOVES == 64'h00_00_00_00_00_40_00_00) $display("5. passed!");
        else $display("5. failed.");
        
        // TEST 6
        UNIT = 64'h00_00_00_04_00_00_00_00;
        WHITE_UNITS = 64'h00_00_00_00_0a_00_00_00;
        EMPTY = 64'hff_ff_ff_fb_f5_ff_ff_ff;
        state = 11'b00_1000_1111_0;
        #10;
        assert (MOVES == 64'h00_00_00_00_0e_00_00_00) $display("6. passed!");
        else $display("6. failed.");
  
        $finish;
    end
endmodule
