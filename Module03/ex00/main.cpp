#include "ClapTrap.hpp"

int main(void) {
	ClapTrap jabae("jabae");
	ClapTrap jihyukim("jihyukim");
	ClapTrap daekim = jihyukim;
	/* 컴퓨터 내부에서 선언 즉시 할당할 경우, 할당연산자 다음에 복사생성자가 불려짐
	copy assignment ~
	copy constructor called ~ */

	jabae.attack("jihyukim");
	jihyukim.takeDamage(5);
	/* unsigned int 형식, 
	음수도 3바이트 안의 숫자라면 컴파일 후에
	실행시에 오버플로우 | 언더플로우도 실행됨 
	3바이트 범위를 넘어가면, 컴파일에서 에러 발생 */
	jihyukim.beRepaired(5);

	return 0;
}
