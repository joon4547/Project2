#include <iostream>
using namespace std;

class SinivelCap
{
public:
	void Take() const { cout << "�๰�� ��~ ���ϴ�" << endl; }
};

class SneezeCap
{
public:
	void Take() const { cout << "��ä�Ⱑ �½��ϴ�" << endl; }
};

class SnuffleCap
{
public:
	void Take() const{ cout << "�ڰ� �� �Ը��ϴ� " << endl; }
};

class ColdPatient
{
public:
	void TakeSinivelCap(const SinivelCap &cap) const { cap.Take(); }
	void TakeSneezeCap(const SneezeCap &cap) const { cap.Take(); }
	void TakeSuffleCap(const SnuffleCap &cap)const { cap.Take(); }
};

int main(void)
{
	SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;

	ColdPatient sufferer;
	sufferer.TakeSinivelCap(scap);
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSuffleCap(ncap);
	return 0;
}