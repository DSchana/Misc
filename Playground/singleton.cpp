#include <cstdio>

using namespace std;

class Sing {
	private:
		static Sing* instance;
		Sing() {}
		virtual ~Sing();

	public:
		static Sing *getInstance();
		int num = 0;
};

Sing* Sing::getInstance() {
	if (instance == NULL) {
		instance = new Sing();
	}

	return instance;
}

Sing::~Sing() {
	delete instance;
	instance = NULL;
}

int main() {
	printf("%d\n", Sing::getInstance()->num);
	Sing::getInstance()->num = 4;
	printf("%d\n", Sing::getInstance()->num);

	return 0;
}
