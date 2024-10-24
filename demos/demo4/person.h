// Person.h 
#ifndef PERSON_H 
#define PERSON_H 

class Person { 
	public: 
		Person(std::string name, int age); 
		
		std::string getName(); 
		int getAge(); 
		
		void setName(std::string name); 
		void setAge(int age); 
        
		~Person();

	private: 
		std::string name; 
		int age; 
}; 

#endif
