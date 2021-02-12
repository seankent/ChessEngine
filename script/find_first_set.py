
# for i in range(1, 64):
# 	print("            else if (LS1B_comb[{}]) i <= 6'd{};".format(i, i))

print("{", end='')
for i in range(63, -1 , -1):
	print("U64[{}], ".format(i), end='')
