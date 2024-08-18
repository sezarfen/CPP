#include <iostream>

class A{
	public:
		void test(){
			std::cout << "a" << std::endl;
		}
};

class B : public A{
	public:
		virtual void test(){
			std::cout << "b" << std::endl;
		}
};

class C: public B{
	public:
		void test(){
			std::cout << "c" << std::endl;
		}
};

// it changes with respect to A and B
void doSomething(B* target){
	target->test();
}

//int main(int argc, char const *argv[])
//{
//	C *obj1 = new C();
//	B *obj2 = obj1;
//	A *obj3 = obj1;
//	obj3->test();
//	obj2->test();
//	obj1->test();
//	return 0;
//}

# include <iostream>
# include <fstream>

int main(int argc, char const *argv[])
{
	  std::string tree = 
"                                                    . \n"
"                                   .         ; \n"
"      .              .              ;%     ;; \n"
"        ,           ,                :;%  %; \n"
"         :         ;                   :;%;'     ., \n"
",.        %;     %;            ;        %;'    ,; \n"
"  ;       ;%;  %%;        ,     %;    ;%;    ,%' \n"
"   %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
"    ;%;      %;        ;%;        % ;%;  ,%;' \n"
"     `%;.     ;%;     %;'         `;%%;.%;' \n"
"      `:;%.    ;%%. %@;        %; ;@%;%' \n"
"         `:%;.  :;bd%;          %;@%;' \n"
"           `@%:.  :;%.         ;@@%;' \n"
"             `@%.  `;@%.      ;@@%; \n"
"               `@%%. `@%%    ;@@%; \n"
"                 ;@%. :@%%  %@@%; \n"
"                   %@bd%%%bd%%:; \n"
"                     #@%%%%%:;; \n"
"                     %@@%%%::; \n"
"                     %@@@%(o);  . ' \n"
"                     %@@@o%;:(.,' \n"
"                 `.. %@@@o%::; \n"
"                    `)@@@o%::; \n"
"                     %@@(o)::; \n"
"                    .%@@@@%::; \n"
"                    ;%@@@@%::;. \n"
"                   ;%@@@@%%:;;;. \n"
"               ...;%@@@@@%%:;;;;,..    \n"
;
  std::ofstream myFile("file.txt");

  myFile << tree;

  myFile.close();

	return 0;
}
