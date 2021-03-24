#include <iostream>

class Example{
	private:
		int num_;
	public:
		int swapper(int newval){
			int old = num_;
			num_ = newval;
			return old;
		};
		void set_val(int val){
			num_ = val;
		};
		void print_val() const{
			std::cout <<num_;
		};
		int return_val() const{
			return num_;
		}


};

int main(){

	Example e;
	e.set_val(12);
	std::cout << "Look at this " << e.return_val() << "\n";
	e.swapper(20);
	std::cout << "How's this now? " << e.return_val() << "\n";
	return 0;
}
