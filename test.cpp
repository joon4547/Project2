class EasyClass
{
private:
	int num;
public:
	void InitNum(int n)	{
		num = n;
	}
	int GetNum() 			//const 선언이 추가되어야 아래의 컴파일 에러 소멸
	{
		return num;
	}
};
class LiveClass{
private:
	int num;
public:
	void InitNum(const EasyClass &easy){
		num = easy.GetNum(); //컴파일 에러발생
	}
};
