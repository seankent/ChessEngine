//==============================================
// ls1b
//==============================================
module ls1b(
    input logic clk,
    input logic rst,           
    input logic [63:0] U64,                 // 64-bit unsigned integer
    output logic [63:0] LS1B,               // least significant 1 bit
    output logic [5:0] i                    // index of least significant 1 bit
    );
    //==============================
    // logic
    //==============================
    logic [63:0] LS1B_comb;                 // least significant 1 bit (comb)
    
    //==============================
    // assign
    //==============================
    assign LS1B_comb = U64 & (~U64 + 1);    // extract least significant 1 bit
    
    //==============================
    // always_ff
    //==============================
    always_ff @(posedge clk) begin
        if (rst) begin
            LS1B <= 64'b0;
            i <= 6'b0;
        end else begin
            LS1B <= LS1B_comb;
            if (LS1B_comb[0]) i <= 6'd0;
            else if (LS1B_comb[1]) i <= 6'd1;
            else if (LS1B_comb[2]) i <= 6'd2;
            else if (LS1B_comb[3]) i <= 6'd3;
            else if (LS1B_comb[4]) i <= 6'd4;
            else if (LS1B_comb[5]) i <= 6'd5;
            else if (LS1B_comb[6]) i <= 6'd6;
            else if (LS1B_comb[7]) i <= 6'd7;
            else if (LS1B_comb[8]) i <= 6'd8;
            else if (LS1B_comb[9]) i <= 6'd9;
            else if (LS1B_comb[10]) i <= 6'd10;
            else if (LS1B_comb[11]) i <= 6'd11;
            else if (LS1B_comb[12]) i <= 6'd12;
            else if (LS1B_comb[13]) i <= 6'd13;
            else if (LS1B_comb[14]) i <= 6'd14;
            else if (LS1B_comb[15]) i <= 6'd15;
            else if (LS1B_comb[16]) i <= 6'd16;
            else if (LS1B_comb[17]) i <= 6'd17;
            else if (LS1B_comb[18]) i <= 6'd18;
            else if (LS1B_comb[19]) i <= 6'd19;
            else if (LS1B_comb[20]) i <= 6'd20;
            else if (LS1B_comb[21]) i <= 6'd21;
            else if (LS1B_comb[22]) i <= 6'd22;
            else if (LS1B_comb[23]) i <= 6'd23;
            else if (LS1B_comb[24]) i <= 6'd24;
            else if (LS1B_comb[25]) i <= 6'd25;
            else if (LS1B_comb[26]) i <= 6'd26;
            else if (LS1B_comb[27]) i <= 6'd27;
            else if (LS1B_comb[28]) i <= 6'd28;
            else if (LS1B_comb[29]) i <= 6'd29;
            else if (LS1B_comb[30]) i <= 6'd30;
            else if (LS1B_comb[31]) i <= 6'd31;
            else if (LS1B_comb[32]) i <= 6'd32;
            else if (LS1B_comb[33]) i <= 6'd33;
            else if (LS1B_comb[34]) i <= 6'd34;
            else if (LS1B_comb[35]) i <= 6'd35;
            else if (LS1B_comb[36]) i <= 6'd36;
            else if (LS1B_comb[37]) i <= 6'd37;
            else if (LS1B_comb[38]) i <= 6'd38;
            else if (LS1B_comb[39]) i <= 6'd39;
            else if (LS1B_comb[40]) i <= 6'd40;
            else if (LS1B_comb[41]) i <= 6'd41;
            else if (LS1B_comb[42]) i <= 6'd42;
            else if (LS1B_comb[43]) i <= 6'd43;
            else if (LS1B_comb[44]) i <= 6'd44;
            else if (LS1B_comb[45]) i <= 6'd45;
            else if (LS1B_comb[46]) i <= 6'd46;
            else if (LS1B_comb[47]) i <= 6'd47;
            else if (LS1B_comb[48]) i <= 6'd48;
            else if (LS1B_comb[49]) i <= 6'd49;
            else if (LS1B_comb[50]) i <= 6'd50;
            else if (LS1B_comb[51]) i <= 6'd51;
            else if (LS1B_comb[52]) i <= 6'd52;
            else if (LS1B_comb[53]) i <= 6'd53;
            else if (LS1B_comb[54]) i <= 6'd54;
            else if (LS1B_comb[55]) i <= 6'd55;
            else if (LS1B_comb[56]) i <= 6'd56;
            else if (LS1B_comb[57]) i <= 6'd57;
            else if (LS1B_comb[58]) i <= 6'd58;
            else if (LS1B_comb[59]) i <= 6'd59;
            else if (LS1B_comb[60]) i <= 6'd60;
            else if (LS1B_comb[61]) i <= 6'd61;
            else if (LS1B_comb[62]) i <= 6'd62;
            else if (LS1B_comb[63]) i <= 6'd63;
            else i <= 6'd0;
        end
    end
    
endmodule
