#include <iostream>
#include <string>
#include <vector>

class Cube 
{
public:
	Cube ();
	void cube_creator(std::string str);
	void fill_cube (std::string str);
	void rotate_left (int cube_pos);
	void rotate_right (int cube_pos);
	void rotate_up (int cube_pos);
	void rotate_down (int cube_pos);
	void encription(std::string encript_code);
	void description(std::string decript_code);
	void show();
private:
	std::string cord_val;	
	int count;
	std::vector <Cube> cubs;

};

int main () {
	std::string str;
	std::string enc_des;
	std::string code;
	std::cout << "Pleace Input ENCRIPTION/DESCRIPTION Text"<< std::endl;
	std::cin >> str;
	std::cout << "For ENCRIPTION Press E, For DESCRIPTION Prss D" << std::endl;
	std::cin >> enc_des;
	std::cout << "Pleace Input Rotation Code, For exemple (Cube Number:Direction Of Rotation)" << std::endl;
	std::cin >> code;
	Cube cube;
	cube.cube_creator(str);
	cube.fill_cube(str);
	if (enc_des[0] == 'e' || enc_des[0] == 'E') {
		cube.encription(code);	
	}else if (enc_des[0] == 'd' || enc_des[0] == 'D') {
		cube.description(code);
	} else {
		std::cout <<"Wrong input! ! !" << std::endl;
		return -1;
	}
	cube.show();
}


Cube::Cube () {
	this->cord_val = "&&&&&&&&";
	this->count = 0;
}

void Cube::cube_creator (std::string str) {
	Cube obj;
	if (str.length() > 8) {
		if (str.length() % 8 == 0) {
			this->count += str.length() / 8;
		} else {
			this->count += str.length() / 8 + 1;
		}				
	} else {
		this->count = 1;
	}
	for (int i = 0; i < count; ++i) {
		this->cubs.push_back(obj);
	}
}


void Cube::fill_cube (std::string str) {
	for (int i = 0; i < this->count; ++i) {
		for (int j = 0; j < 8 ; ++j) {
			if (i * 8 + j >= str.length()) {
				cubs[i].cord_val[j] = '&';
			} else {
				cubs[i].cord_val[j] = str[j + i * 8];
			}
		}
	
	}
}

void Cube::rotate_left(int cube_pos) {
	std::string left = cubs[cube_pos].cord_val;
	std::string tmp = left;	
	tmp[0] = left[1];
	tmp[1] = left[5];
	tmp[2] = left[6];
	tmp[3] = left[2];
	tmp[4] = left[0];
	tmp[5] = left[4];
	tmp[6] = left[7];
	tmp[7] = left[3];
	cubs[cube_pos].cord_val = tmp;	
}


void Cube::rotate_right(int cube_pos) {
	std::string right = cubs[cube_pos].cord_val;
	std::string tmp = right;	
	tmp[0] = right[4];
	tmp[1] = right[0];
	tmp[2] = right[3];
	tmp[3] = right[7];
	tmp[4] = right[5];
	tmp[5] = right[1];
	tmp[6] = right[2];
	tmp[7] = right[6];
	cubs[cube_pos].cord_val = tmp;	
}


void Cube::rotate_up(int cube_pos) {
	std::string up = cubs[cube_pos].cord_val;
	std::string tmp = up;	
	tmp[0] = up[4];
	tmp[1] = up[5];
	tmp[2] = up[1];
	tmp[3] = up[0];
	tmp[4] = up[7];
	tmp[5] = up[6];
	tmp[6] = up[2];
	tmp[7] = up[3];
	cubs[cube_pos].cord_val = tmp;	
}


void Cube::rotate_down(int cube_pos) {
	std::string down = cubs[cube_pos].cord_val;
	std::string tmp = down;	
	tmp[0] = down[3];
	tmp[1] = down[2];
	tmp[2] = down[6];
	tmp[3] = down[7];
	tmp[4] = down[0];
	tmp[5] = down[1];
	tmp[6] = down[5];
	tmp[7] = down[4];
	cubs[cube_pos].cord_val = tmp;	
}

void Cube::encription(std::string encript_code) {
	char num;
	int pos = 0;
	for (int i = 0; i < encript_code.length(); ++i) {
		if (encript_code[i] >= '0' && encript_code[i] <= '9') {
			num = encript_code[i];	
		pos = (int)num - 48;
		} else if(encript_code[i] == ':') {
			continue;
		} else	if(encript_code[i] == 'R' || encript_code[i] == 'r') {
			this->rotate_right(pos);
		} else 	if(encript_code[i] == 'L' || encript_code[i] == 'l') {
			this->rotate_left(pos);
		} else 	if(encript_code[i] == 'U' || encript_code[i] == 'u') {
			this->rotate_up(pos);
		} else 	if(encript_code[i] == 'D' || encript_code[i] == 'd') {
			this->rotate_down(pos);
		} else {
			std::cout<<"Wrong Input! ! !" << std::endl;
			return;
		}
	}	
}


void Cube::description(std::string decript_code) {
	char num;
	int pos = 0;
	for (int i = 0; i < decript_code.length(); ++i) {
		if (decript_code[i] >= '0' && decript_code[i] <= '9') {
			num = decript_code[i];	
		pos = (int)num - 48;
		} else if(decript_code[i] == ':') {
			continue;
		} else	if(decript_code[i] == 'R' || decript_code[i] == 'r') {
			this->rotate_left(pos);
		} else 	if(decript_code[i] == 'L' || decript_code[i] == 'l') {
			this->rotate_right(pos);
		} else 	if(decript_code[i] == 'U' || decript_code[i] == 'u') {
			this->rotate_down(pos);
		} else 	if(decript_code[i] == 'D' || decript_code[i] == 'd') {
			this->rotate_up(pos);
		} else {
			std::cout<<"Wrong Input! ! !" << std::endl;
			return;
		}
	}	
}


void Cube::show() {
	std::string out = "";
	for (int i = 0; i < this->count; i++) {
		out += cubs[i].cord_val;
	}
	std::cout << out <<std::endl;
}
