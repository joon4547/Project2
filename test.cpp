class EasyClass
{
private:
	int num;
public:
	void InitNum(int n)	{
		num = n;
	}
	int GetNum() 			//const ������ �߰��Ǿ�� �Ʒ��� ������ ���� �Ҹ�
	{
		return num;
	}
};
class LiveClass{
private:
	int num;
public:
	void InitNum(const EasyClass &easy){
		num = easy.GetNum(); //������ �����߻�
	}
};
