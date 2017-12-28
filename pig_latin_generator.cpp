#include <iostream>
#include <fstream>

std::string translator(std::string userInput){
	std::string pigLatinWord;
	bool pigSwitch = true;
	bool quoteSwitch = true;
	if(userInput.find("\"") != std::string::npos){	//contains quote
		quoteSwitch = false;
		if(userInput.find("\"") == 0 && (userInput.find("\"",1) != (userInput.length()-1))){	//quote at beg and not end
			if(isupper(userInput[1])){
				if(userInput.substr(1,1) == "A" || userInput.substr(1,1) == "E" || userInput.substr(1,1) == "I" || userInput.substr(1,1) == "O" || userInput.substr(1,1) == "U"){	//vowel
					pigSwitch = false;
					pigLatinWord = userInput.append("ay");
				}
				if(userInput.substr(1,2) == "Sh" || userInput.substr(1,2) == "Th" || userInput.substr(1,2) == "Ph" || userInput.substr(1,2) == "Ch"){	//cons cluster
					pigSwitch = false;
					userInput[1] = tolower(userInput[1]);
					userInput[3] = toupper(userInput[3]);
					pigLatinWord = "\"" + userInput.substr(3,userInput.length()) + userInput.substr(1,2) + "ay";
				}
				if(pigSwitch){
					userInput[1] = tolower(userInput[1]);
					userInput[2] = toupper(userInput[2]);
					pigLatinWord = "\"" + userInput.substr(2,userInput.length()) + userInput.substr(1,1) + "ay";
				}
			}
			else{
				if(userInput.substr(1,1) == "a" || userInput.substr(1,1) == "e" || userInput.substr(1,1) == "i" || userInput.substr(1,1) == "o" || userInput.substr(1,1) == "u"){	//vowel
					pigSwitch = false;
					pigLatinWord = userInput.append("ay");
					
				}
				if(userInput.substr(1,2) == "sh" || userInput.substr(1,2) == "th" || userInput.substr(1,2) == "ph" || userInput.substr(1,2) == "ch"){	//cons cluster
					pigSwitch = false;
					pigLatinWord = "\"" + userInput.substr(3,userInput.length()) + userInput.substr(1,2) + "ay";
				}
				if(pigSwitch){
					pigLatinWord = "\"" + userInput.substr(2,userInput.length()) + userInput.substr(1,1) + "ay";
				}
				
			}
		}
		
		if(userInput.find("\"",1) == (userInput.length()-1) && !(userInput.find("\"") == 0 )){	//quote at end and not beg
			if(isupper(userInput[0])){
				if(userInput.substr(0,1) == "A" || userInput.substr(0,1) == "E" || userInput.substr(0,1) == "I" || userInput.substr(0,1) == "O" || userInput.substr(0,1) == "U"){
					pigSwitch = false;
					pigLatinWord = userInput.substr(0,userInput.length()-1) + "ay\"";
				}
				if(userInput.substr(0,2) == "Sh" || userInput.substr(0,2) == "Th" || userInput.substr(0,2) == "Ph" || userInput.substr(0,2) == "Ch"){
					pigSwitch = false;
					userInput[0] = tolower(userInput[0]);
					userInput[2] = toupper(userInput[2]);
					pigLatinWord = userInput.substr(2,userInput.length()-3) + userInput.substr(0,2) + "ay\"";
				}
				if(pigSwitch){
					userInput[0] = tolower(userInput[0]);
					userInput[1] = toupper(userInput[1]);
					pigLatinWord = userInput.substr(1,userInput.length()-2) + userInput[0] + "ay\"";
					
				}
			}
			else{
				if(userInput.substr(0,1) == "a" || userInput.substr(0,1) == "e" || userInput.substr(0,1) == "i" || userInput.substr(0,1) == "o" || userInput.substr(0,1) == "u"){
					pigSwitch = false;
					pigLatinWord = userInput.substr(0,userInput.length()-1) + "ay\"";
				}
				if(userInput.substr(0,2) == "sh" || userInput.substr(0,2) == "th" || userInput.substr(0,2) == "ph" || userInput.substr(0,2) == "ch"){
					pigSwitch = false;
					pigLatinWord = userInput.substr(2,userInput.length()-3) + userInput.substr(0,2) + "ay\"";
				}
				if(pigSwitch){
					pigLatinWord = userInput.substr(1,userInput.length()-2) + userInput[0] + "ay\"";
				}
				
			}
		}
		
		if(userInput.find("\"") == 0 && userInput.find("\"",1) == (userInput.length()-1)){	//quote at beg & end
			if(isupper(userInput[1])){
				if(userInput.substr(1,1) == "A" || userInput.substr(1,1) == "E" || userInput.substr(1,1) == "I" || userInput.substr(1,1) == "O" || userInput.substr(1,1) == "U"){	//vowel
					pigSwitch = false;
					pigLatinWord = userInput.substr(0,userInput.length()-1) + "ay\"";
				}
				if(userInput.substr(1,2) == "Sh" || userInput.substr(1,2) == "Th" || userInput.substr(1,2) == "Ph" || userInput.substr(1,2) == "Ch"){	//cons cluster
					pigSwitch = false;
					userInput[1] = tolower(userInput[1]);
					userInput[3] = toupper(userInput[3]);
					pigLatinWord = "\"" + userInput.substr(3,userInput.length()-4) + userInput.substr(1,2) + "ay\"";
				}
				if(pigSwitch){
					userInput[1] = tolower(userInput[1]);
					userInput[2] = toupper(userInput[2]);
					pigLatinWord = "\"" + userInput.substr(2,userInput.length()-3) + userInput[1] + "ay\"";
					
				}
			}
			else{
				if(userInput.substr(1,1) == "a" || userInput.substr(1,1) == "e" || userInput.substr(1,1) == "i" || userInput.substr(1,1) == "o" || userInput.substr(1,1) == "u"){	//vowel
					pigSwitch = false;
					pigLatinWord = userInput.substr(0,userInput.length()-1) + "ay\"";
				}
				if(userInput.substr(1,2) == "sh" || userInput.substr(1,2) == "th" || userInput.substr(1,2) == "ph" || userInput.substr(1,2) == "ch"){	//cons cluster
					pigSwitch = false;
					pigLatinWord = "\"" + userInput.substr(3,userInput.length()-4) + userInput.substr(1,2) + "ay\"";
				}
				if(pigSwitch){
					pigLatinWord = "\"" + userInput.substr(2,userInput.length()-3) + userInput[1] + "ay\"";
				}
			}
		}
	}
	if(quoteSwitch){
		if(isupper(userInput[0])){
			if(userInput.substr(0,1) == "A" || userInput.substr(0,1) == "E" || userInput.substr(0,1) == "I" || userInput.substr(0,1) == "O" || userInput.substr(0,1) == "U"){
				pigLatinWord = userInput.append("ay");
				pigSwitch = false;
			}	 
			if(userInput.substr(0,2) == "Th" || userInput.substr(0,2) == "Ph" || userInput.substr(0,2) == "Sh" || userInput.substr(0,2) == "Ch"){
				userInput[0] = tolower(userInput[0]);
				userInput[2] = toupper(userInput[2]);
				pigLatinWord = userInput.substr(2,userInput.length()-2) + userInput.substr(0,2) + "ay";
				pigSwitch = false;
			}
			if(pigSwitch){
				userInput[0] = tolower(userInput[0]);
				userInput[1] = toupper(userInput[1]);
				pigLatinWord = userInput.substr(1,userInput.length()-1) + userInput[0] + "ay";
			}	
		}
		else{
			if(userInput.substr(0,1) == "a" || userInput.substr(0,1) == "e" || userInput.substr(0,1) == "i" || userInput.substr(0,1) == "o" || userInput.substr(0,1) == "u"){
				pigLatinWord = userInput.append("ay");
				pigSwitch = false;	
			}	 
			if(userInput.substr(0,2) == "th" || userInput.substr(0,2) == "ph" || userInput.substr(0,2) == "sh" || userInput.substr(0,2) == "ch"){
				pigLatinWord = userInput.substr(2,userInput.length()-2) + userInput.substr(0,2) + "ay";
				pigSwitch = false;
			}
			if(pigSwitch){
				pigLatinWord = userInput.substr(1,userInput.length()-1) + userInput[0] + "ay";
			}
		}
	}
	return pigLatinWord;
	
}
	
std::string symMover (std::string pigLatinWord){
	
	std::string symMovedTransWord;
	if(pigLatinWord.find(".") != std::string::npos || pigLatinWord.find(",") != std::string::npos || pigLatinWord.find(":") != std::string::npos || pigLatinWord.find(";") != std::string::npos || pigLatinWord.find("!") != std::string::npos || pigLatinWord.find("?") != std::string::npos ){
		int symPos = pigLatinWord.find_first_of(".,;:?!");
		std::string firstHalf = pigLatinWord.substr(0,symPos);
		std::string secondHalf = pigLatinWord.substr(symPos+1,pigLatinWord.length()-1);
		symMovedTransWord = firstHalf + secondHalf + pigLatinWord[symPos];
	}
	else{
		symMovedTransWord = pigLatinWord;
	}
	return symMovedTransWord;
}


int main(){
	std::ifstream readFile;
	readFile.open("sentence.txt");
	std::string indivWord;
	std::string translatedString;
	if(readFile.is_open()){
		while(!readFile.eof()){
			readFile >> indivWord;
			translatedString.append(symMover(translator(indivWord)) + " ");
			
		}
	}
	std::cout << translatedString;
	readFile.close();
	return 0;
}
