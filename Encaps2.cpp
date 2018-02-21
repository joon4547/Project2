#include <iostream>
using namespace std;

class SinivalCap
{
public:
	void Take() const { cout << "Äà¹°" << endl; }
};

class SneezeCap
{
public:
	void Take() const { cout << " ÀçÃ¤±â" << endl; }
};

class SnuffleCap
{
public:
	void Take() const { cout << "ÄÚ¸·Èû" << endl; }
};

class CONTAC600	//Ä¸½¶È­°¡ µÇ¾îÀÖ´Â class // °´Ã¼¸¦ ¸É¹ö·Î µÎ¾ú´Ù.
{
private:
	SinivalCap sin;  //ClassName objName; º¯¼ö¼±¾ð¹æ½Ä.
	SneezeCap sne;
	SnuffleCap snu;

public:
	void Take() const
	{
		sin.Take();
		sne.Take();
		snu.Take();
	}
};

class ColdPatient //°£´ÜÇØÁü
{
public:
	void TakeCONTAC600(const CONTAC600 &cap) const { cap.Take(); }
};

int main(void)
{
	CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC600(cap);
	return 0;
}