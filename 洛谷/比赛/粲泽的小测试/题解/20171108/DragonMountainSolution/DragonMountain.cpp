#include <iostream>
#include <cstring>
using namespace std;
int Pow(int k, int times)//math���pow�ƺ��Ǹ����͵ģ������� 
{
    int l, total=1;
    for(l=0;l<times;l++)
        total*=k;
    return total;//�ݼ��� 
}
int TransCode(int m, bool TheMessage[])//�����ƴ���ת������ĸ 
{
    int n, Value=0;
    for(n=3;n<8;n++)
        Value+=TheMessage[m+n]*Pow(2, 7-n);
    return (Value+'A');
}
int main()
{
    int i, j, flag=0, Err=0, Number='Z'+1;
    bool DragonMessage[171111];
    int Plus[8]={0}, NumberList[171111]={0};
    char Translation[171111], GetMessage[171111];
    cin>>GetMessage;
    int Length=strlen(GetMessage);
    if(Length%8!=0)
        Err=1;
    for(i=0;i<Length;i++)
    {
        DragonMessage[i]=GetMessage[i]-'0';//ȫ��ת��Ϊ�����Ʋ����ж��Ƿ���ڼٴ���
        if((GetMessage[i]-'0')>1||(GetMessage[i]-'0')<0)
            Err=1;
    }
    for(i=0;i<Length&&Err==0;i+=8)
        if(DragonMessage[i]==1&&DragonMessage[i+1]==0&&DragonMessage[i+2]==1)//�ҵ�101
		{
            Translation[flag++]=TransCode(i, DragonMessage);//�������ĸ
			if(Translation[flag-1]>'Z')//���ܳ���ZŶ
				Err=1;
        }
		else if(DragonMessage[i]==1&&DragonMessage[i+1]==1&&DragonMessage[i+2]==1)//�ҵ�111
            Translation[flag++]=' ';
        else if(DragonMessage[i]==0)//�ҵ�0
        {
            memset(Plus, 0, sizeof(Plus));
            if(DragonMessage[i+8]!=0||i+9>=Length)//�жϺ����Ƿ���0xxxxxxx
            {
                Err=1;
                break;
            }
            for(j=7;j>=1;j--)//���ӷ���ֻ��ǰ��7λ�����һλ��ȥ
            {
                Plus[j]+=DragonMessage[i+j-1];
                Plus[j]+=DragonMessage[i+j+7];
                if(Plus[j]==2)
                {
                    Plus[j]=0;
                    Plus[j-1]++;
                }
            }
            Translation[flag++]=Number;
            for(j=0;j<8;j++)
                NumberList[Number]+=Plus[j]*Pow(2, 7-j);//ת��Ϊ10����
            Number++;
            i+=8;
        }
        else//����������ǲ�����
        {
            Err=1;
            break;
        }
    if(Err==1)
        cout<<"Error";
    else
        for(i=0;i<flag;i++)
            if(Translation[i]>'Z')
                cout<<NumberList[Translation[i]];
            else
                cout<<Translation[i];//������
    return 0;
}
