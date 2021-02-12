//==============================================
// timescale
//==============================================
`timescale 1ns / 1ps

//==============================================
// ls1b_tb
//==============================================
module ls1b_tb;
    //==============================
    // logic
    //==============================
    logic clk;
    logic rst;
    logic [63:0] U64;       // bitboard (64-bit)
    logic [63:0] LS1B;      // least significant 1 bit
    logic [5:0] i;          // index of least significant 1 bit
    
    //==============================
    // uut
    //==============================
    ls1b uut
    (
        .clk(clk),
        .rst(rst),
        .U64(U64),
        .LS1B(LS1B),
        .i(i)
    );
    
    //==============================
    // clk
    //==============================
    always #5 clk = !clk;
    
    //==============================
    // initial
    //==============================
    initial begin
    $display("Running Simulation!");
        clk = 1'b0;
        rst = 1'b0;
        U64 = 64'b0;
    #10;                            // t = 10ns
        rst = 1'b1;
    #10;                            // t = 20ns
        rst = 1'b0;
    #10;                            // t = 30ns
        U64 = 64'h00_00_00_00_00_00_00_00;
    #10;                            // t = 40ns
        assert (LS1B == 64'h00_00_00_00_00_00_00_00) else $display("    Test 0 Failed (LS1B).");
        assert (i == 6'd0) else $display("    Test 0 Failed (i).");
        U64 = 64'h00_00_00_00_00_00_00_01;
    #10;                            // t = 50ns 
        assert (LS1B == 64'h00_00_00_00_00_00_00_01) else $display("    Test 1 Failed (LS1B).");
        assert (i == 6'd0) else $display("    Test 1 Failed (i).");
        U64 = 64'h80_00_00_FF_01_00_00_00;
    #10;                            // t = 60ns
        assert (LS1B == 64'h00_00_00_00_01_00_00_00) else $display("    Test 2 Failed (LS1B).");
        assert (i == 6'd24) else $display("    Test 2 Failed (i).");
    #10;                            // t = 70ns
    #10;                            // t = 80ns
    #10;                            // t = 90ns  
        
        $finish;
    end
    
endmodule