//==============================================
// top
//==============================================
module top(
    input clk_100mhz,
    input [15:0] sw,
    output logic [1:0] led
    );
    
    //==============================
    // logic
    //==============================
    logic clk;
    logic rst;
    logic [63:0] WP;
    logic [63:0] BLACK_UNITS;
    logic [63:0] BP;
    logic [63:0] EMPTY;
    logic [63:0] FILE_EP;
    logic [63:0] PAWN_RIGHT;
    logic [63:0] PAWN_LEFT;
    logic [63:0] PAWN_FORWARD_1;
    logic [63:0] PAWN_FORWARD_2;
    logic [63:0] PAWN_RIGHT_PROMOTION;
    logic [63:0] PAWN_LEFT_PROMOTION;
    logic [63:0] PAWN_FORWARD_PROMOTION;
    logic [63:0] PAWN_RIGHT_EP;
    logic [63:0] PAWN_LEFT_EP;
    
    //==============================
    // assign
    //==============================
    assign clk = clk_100mhz;
    assign rst = 0;
    assign WP = {sw[15:0], sw[15:0], sw[15:0], sw[15:0]};
    assign BLACK_UNITS = {sw[15:0], sw[15:0], sw[15:0], sw[15:0]};
    assign BP = {sw[15:0], sw[15:0], sw[15:0], sw[15:0]};
    assign EMPTY = {sw[15:0], sw[15:0], sw[15:0], sw[15:0]};
    assign FILE_EP = {sw[15:0], sw[15:0], sw[15:0], sw[15:0]};
    //assign BLACK_UNITS = 64'b0;
    //assign led[1:0] = PAWN_RIGHT[1:0];
    
    //==============================
    // modules
    //==============================
    move_gen_WP move_gen_WP_0
    (
        .clk(clk),
        .rst(rst),
        .WP(WP),
        .BLACK_UNITS(BLACK_UNITS),
        .BP(BP),
        .EMPTY(EMPTY),
        .FILE_EP(FILE_EP),
        .PAWN_RIGHT(PAWN_RIGHT),
        .PAWN_LEFT(PAWN_LEFT),
        .PAWN_FORWARD_1(PAWN_FORWARD_1),
        .PAWN_FORWARD_2(PAWN_FORWARD_2),
        .PAWN_RIGHT_PROMOTION(PAWN_RIGHT_PROMOTION),
        .PAWN_LEFT_PROMOTION(PAWN_LEFT_PROMOTION),
        .PAWN_FORWARD_PROMOTION(PAWN_FORWARD_PROMOTION),
        .PAWN_RIGHT_EP(PAWN_RIGHT_EP),
        .PAWN_LEFT_EP(PAWN_LEFT_EP)
    );
    
    //==============================
    //  always_ff
    //==============================
    logic [5:0] count;
    always_ff @(posedge clk) begin
        count <= count + 1;
        case (count % 9)
            0: led[1:0] <= {PAWN_RIGHT[count], PAWN_RIGHT[count - 1]};
            1: led[1:0] <= {PAWN_LEFT[count], PAWN_LEFT[count - 1]};
            2: led[1:0] <= {PAWN_FORWARD_1[count], PAWN_FORWARD_1[count - 1]};
            3: led[1:0] <= {PAWN_FORWARD_2[count], PAWN_FORWARD_2[count - 1]};
            4: led[1:0] <= {PAWN_RIGHT_PROMOTION[count], PAWN_RIGHT_PROMOTION[count - 1]};
            5: led[1:0] <= {PAWN_LEFT_PROMOTION[count], PAWN_LEFT_PROMOTION[count - 1]};
            6: led[1:0] <= {PAWN_FORWARD_PROMOTION[count], PAWN_FORWARD_PROMOTION[count - 1]};
            7: led[1:0] <= {PAWN_RIGHT_EP[count], PAWN_RIGHT_EP[count - 1]};
            8: led[1:0] <= {PAWN_LEFT_EP[count], PAWN_LEFT_EP[count - 1]};
        endcase
    end
    
    
    
endmodule