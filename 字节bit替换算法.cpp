//�ֽ� bit 1λ���λ�滻����
//��7D(0111 1101) �滻ֵ0a(0000 1010) �滻�㷨0e(0000 1110) ���7b(0111 1011) 
//BYTE byte Ҫ�������ֽڣ����Ƿ��ؽ��
//BYTE iCal �滻���㷨 ��0x07(0000 0111) 1��ʾҪ�滻��λ��
//BYTE iValue Ҫ���µ�bitֵ����0x03(0000 0011)
BYTE nBitCala(BYTE byte,BYTE iCal,BYTE iValue)
{
	BYTE rBitIs1[8] = {0};//��¼�㷨Ϊ1��bitλ,���滻��λ��
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
			if(((byte >> i)&1) == 1)//ԭ�ֽ�bit����1
			{
				if(((iValue >> i)&1) == 1);//������1 ����
				else//ֵ��bitΪ0
				{
					byte &= ~ival[i];//����Ӧbit��Ϊ0
				}
			}
			else//ԭ�ֽ�bit����0
			{
				if(((iValue >> i)&1) == 1)//
				{
					byte |= ival[i];
				}
				else;//������0 ����
			}
		}
	}
	return byte;
}

