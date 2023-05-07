//字节 bit 1位或多位替换操作
//如7D(0111 1101) 替换值0a(0000 1010) 替换算法0e(0000 1110) 结果7b(0111 1011) 
//BYTE byte 要操作的字节，且是返回结果
//BYTE iCal 替换的算法 如0x07(0000 0111) 1表示要替换的位置
//BYTE iValue 要更新的bit值，如0x03(0000 0011)
BYTE nBitCala(BYTE byte,BYTE iCal,BYTE iValue)
{
	BYTE rBitIs1[8] = {0};//记录算法为1的bit位,即替换的位置
	BYTE ival[8] = {1,2,4,8,16,32,64,128};
	W_UINT2 i;

	for(i = 0;i < 8;i++)
	{
		if((iCal>>i)&1)
		{
			rBitIs1[i] = 1;
		}
	}
	
	for(i = 0;i < 8;i++)
	{
		if(rBitIs1[i] == 1)
		{
			if(((byte >> i)&1) == 1)//原字节bit等于1
			{
				if(((iValue >> i)&1) == 1);//都等于1 不动
				else//值的bit为0
				{
					byte &= ~ival[i];//把相应bit置为0
				}
			}
			else//原字节bit等于0
			{
				if(((iValue >> i)&1) == 1)//
				{
					byte |= ival[i];
				}
				else;//都等于0 不动
			}
		}
	}
	return byte;
}

