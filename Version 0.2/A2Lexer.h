#include "RoughLexer.h"
/*****************************************************************
* PROJECT - A2 LEXICON PARSER
* ----------------------------------------------------------------
* Team Name : DeMorgan's loss.
* Authors   : Can Dalgir, David Luong.
* Project   : 1
* Style     : Pragmatic / Pair Programming.
* ----------------------------------------------------------------*/

/*****************************************************************
* CLASS | RuleSet_A2
* ----------------------------------------------------------------
* The designed class is exclusively for reading the A2 lexers
* ruleset(s) for programming the A2 lexer/parser.
* ----------------------------------------------------------------
*
* public -> This section provides accesible functions to the 
*           ruleset only.
*
* private -> This section is designed to hold variables that
*            can only be access for the A2 lexer ruleset.
* -
******************************************************************/
class RuleSet_A2
{
	public:

		/*****************************************************************
		* VECTOR<STRING>| parseID
		* ----------------------------------------------------------------
		* This vector function is designed to parse the ID of the A2
		* lexer ruleset(s). The parseID's are the first initial number
		* structures to determine the key's attached id.
		*
		* RETURNS: Parsed ID Vector.
		******************************************************************/
		vector<string> parseID(vector<string> parseStack);

		/*****************************************************************
		* VECTOR<STRING>| parseKey
		* ----------------------------------------------------------------
		* This vector function is designed to parse the Key of the A2
		* lexer ruleset(s). Key's are generally keywords to describe the
		* A2 lexers input character(s) set(s).
		*
		* RETURNS: Parsed Key Vector.
		******************************************************************/
		vector<string> parseKey(vector<string> parseStack);

		/*****************************************************************
		* VECTOR<STRING>| parseOp
		* ----------------------------------------------------------------
		* This vector function is designed to parse the what the key
		* of the A2 ruleset members look like. Key's are generally keywords
		* to describe the A2 lexers input character(s) set(s).
		* Ex: 10 kwdprog = "prog"
		*
		* + '10' is the ID.
		* + 'kwdprog' is the key.
		* + 'prog' is the Op(short for operation.)
		*
		* RETURNS: Parsed Operation Vector.
		******************************************************************/
		vector<string> parseOp(vector<string> parseStack);

		/*****************************************************************
		* VECTOR<STRING>| ruleSet_
		* ----------------------------------------------------------------
		* This vector function is designed to read in the A2 Lexicon 
		* ruleset and stores them into the desired vector structure. 
		* RETURNS: A2 Lexicon ruleset.
		******************************************************************/
		vector<string> ruleSet_();

	private:

		std::vector<std::string> A2RuleSet; //A2 Lexicon Ruleset vector.
		                                    //Holds all the required ruleset(s).

};

/*****************************************************************
* CLASS | Parser_A2
* ----------------------------------------------------------------
* The designed class is exclusively for parsing the desired
* input from the user through a provided '.txt' file.
* 
* NOTE: The parser is dynamic and currently is following the
*       A2 Lexicon ruleset(s).
* ----------------------------------------------------------------
*
* public -> This section provides accesible functions to the
*           parser only.
*
* private -> This section is designed to hold variables that
*            can only be access for the parser ruleset.
* -
******************************************************************/
class Parser_A2
{
	public:

		/*****************************************************************
		* VECTOR<STRING>| read_Text
		* ----------------------------------------------------------------
		* This function is designed to read the given '.txt' file with
		* A2 Lexicon parameters to be checked and executed for
		* correct A2 Lexicon ruleset(s).
		*
		* + string File_Name : The name of the '.txt' file that will be 
		*                      queue'd for parsing with A2 Lexicon
		*                      ruleset.
		*
		* RETURNS: Detailed vector<string> stack that has additional '.txt'
		*          file information.
		******************************************************************/
		vector<string> read_Text(string File_Name);

		/*****************************************************************
		* STRING| int_check
		* ----------------------------------------------------------------
		* This function is designed to distinguish between an integer and
		* a float.
		*
		* + string line_ : The substring where the parsing for the int
		*                  float will be executed at.
		*
		* + int _pos     : The position variable where the integer or the
		*                  float has been verified.
		*
		* RETURNS: Parsed Integer or Float with a hardcoded flag.
		******************************************************************/
		string int_check(string line_, int _pos);

		/*****************************************************************
		* STRING| next_token
		* ----------------------------------------------------------------
		* This function is designed to execute the initial parsing process
		* process. The process will accomidate the A2 Lexicon ruleset(s)
		* and parse accordingly.
		*
		* + vector<string> _id        : The id parameter from A2 Lexicon 
		*                               ruleset(s).
		* + vector<string> _key       : The key parameter from A2 Lexicon
		*                               ruleset(s).
		* + vector<string> _operation : The operation parameter from A2 
		*                               Lexicon ruleset(s).
		* + string _line              : The substring that will be
		*                               initially checked for token(s).
		* + string _line_num          : The line number(s) collected
		*                               from the text file stack.
		*
		* RETURNS: Nothing.
		******************************************************************/
		void next_token(vector<string> _id, vector<string> _key, vector<string> _operation, string _line, string _line_num);

		/*****************************************************************
		* STRING| Parser_A2Lexi
		* ----------------------------------------------------------------
		* This function is designed to create the initial parsing process
		* process. The process will accomidate the A2 Lexicon ruleset(s)
		* and parse accordingly.
		*
		* + vector<string> _id        : The id parameter from A2 Lexicon
		*                               ruleset(s).
		* + vector<string> _key       : The key parameter from A2 Lexicon
		*                               ruleset(s).
		* + vector<string> _operation : The operation parameter from A2
		*                               Lexicon ruleset(s).
		* + string _line              : The substring that will be
		*                               initially checked for token(s).
		* + string _line_num          : The line number(s) collected
		*                               from the text file stack.
		*
		* RETURNS: Nothing.
		******************************************************************/
		void Parser_A2Lexi(vector<string> _id, vector<string> _key, vector<string> _operation, vector<string> Text_File);

		void cleanParser_()
		{
			Text_File.clear();
			id_string.clear();
			number_of_lines = 0;
		}

		/*****************************************************************
		* VOID| result_Stack_Out()
		* ----------------------------------------------------------------
		* This function is designed to output the stack in the manner of
		* an LL(1) parser guidelines and it uses the A1 Grammar to
		* determine the right grammar output.
		*
		* RETURNS: Nothing.
		******************************************************************/
		void result_Stack_Out()
		{
			string _line = "";
			string text_ = "";
			ifstream file_("A2SyntaxKey.txt");
			if (file_.is_open())
			{
				while (getline(file_, _line))
				{
					//Line Vector: Overall structure of the program stack.
					Read_File.push_back(_line);
				}
				file_.close();
			}
			else cout << "Unable to open file";
			
			string _output = "";
			for (int i = 0; i < result_Stack.size(); i++)
			{
				result_Stack[i].erase(std::remove(result_Stack[i].begin(), result_Stack[i].end(), ' '), result_Stack[i].end());
				_output += result_Stack[i] + '-';

				bool Opmul = ((result_Stack[i] == "41 ") || (result_Stack[i] == "48") || (result_Stack[i] == "42"));
				bool Opadd = ((result_Stack[i] == "46") || (result_Stack[i] == "47"));
				bool id     = false;
				bool Elist2 = false;
				bool S_Out  = false;
				bool Elist  = false;
				bool S_In   = false;
				bool S_Asgn = false;
				bool Slist  = false;

				if ((i + 1) < result_Stack.size())
					id    = ((result_Stack[i] == "5") && (result_Stack[(i+1)] == "45"));

				//Individual Syntax Grammar
				bool Fatom = ( (id) || (result_Stack[i] == "3") || (result_Stack[i] == "4") || (result_Stack[i] == "5"));
				bool Expression_ = ((result_Stack[i] == "3") || (result_Stack[i] == "4"));
				bool F_ = ((Fatom) || ((result_Stack[i] == "37") && (Expression_) && (result_Stack[i] == "38")));
				bool T_ = ( ((Expression_) && (Opmul) && (F_)) || (F_) );
				bool E_ = (((Expression_) && (Opadd) && (T_)) || (T_));
				bool Expression_2 = ( (Expression_) || (Fatom) );

				//Combinational Syntax Grammar
				if ((result_Stack[i] == "6"))
				{
					for (int _ahead = i; _ahead < result_Stack.size(); _ahead++)
					{
						Fatom = ( (result_Stack[_ahead] == "3 ") || (result_Stack[_ahead] == "4 ") || (result_Stack[_ahead] == "5 ") );
						Expression_ = ((result_Stack[_ahead] == "3") || (result_Stack[_ahead] == "4"));
						Expression_2 = ((Expression_) || (Fatom));
						if (Expression_2)
						{
							break;
						}

					}
					Elist2 = Expression_2;
				}

				if (E_)
				{
					for (int _ahead = i; _ahead < result_Stack.size(); _ahead++)
					{
						Fatom        = ((result_Stack[_ahead] == "3 ") || (result_Stack[_ahead] == "4 ") || (result_Stack[_ahead] == "5 "));
						Expression_  = ((result_Stack[_ahead] == "3") || (result_Stack[_ahead] == "4"));
						Expression_2 = ((Expression_) || (Fatom));
						if (Expression_2)
						{
							break;
						}

					}
					Elist = Expression_2;
				}

				#pragma region S_Out
				if (result_Stack[i] == "23")
				{
					for (int _ahead2 = i; _ahead2 < result_Stack.size(); _ahead2++)
					{
						bool paren1 = (result_Stack[_ahead2] == "37 ");
						if (paren1)
						{
							for (int _ahead = _ahead2; _ahead < result_Stack.size(); _ahead++)
							{
								Fatom = ((result_Stack[_ahead] == "3 ") || (result_Stack[_ahead] == "4 ") || (result_Stack[_ahead] == "5 "));
								Expression_ = ((result_Stack[_ahead] == "3 ") || (result_Stack[_ahead] == "4 "));
								Expression_2 = ((Expression_) || (Fatom));
								if (Expression_2)
								{
									_ahead2 = _ahead;
									break;
								}
							}
							Elist = Expression_2;
						}//IF-STATEMENT-END
						for (int _ahead3 = _ahead2; _ahead3 < result_Stack.size(); _ahead3++)
						{
							bool paren2 = (result_Stack[_ahead3] == "38 ");
							if ((Elist) && (paren1) && (Expression_2)) 
							{
								if (paren2)
								{
									S_Out = true;
									break;
								}
							}
						}
					}//FOR-LOOP-END
				}
				#pragma endregion S_Out


				#pragma region S_In
				if (id)
				{
					if ((i + 2) < result_Stack.size())
					{
						if (result_Stack[(i + 1)] == "45")
						{
							if (result_Stack[(i + 2)] == "22")
							{
								S_In = true;
							}
						}
					}

				}
				#pragma endregion S_In
				
				#pragma region S_Asgn
				if (id)
				{
					if ((i + 1) < result_Stack.size())
					{
						if (result_Stack[(i + 1)] == "45")
						{
							for (int _ahead = (i + 1); _ahead < result_Stack.size(); _ahead++)
							{
								Fatom        = ((result_Stack[_ahead] == "3 ") || (result_Stack[_ahead] == "4 ") || (result_Stack[_ahead] == "5 "));
								Expression_  = ((result_Stack[_ahead] == "3") || (result_Stack[_ahead] == "4"));
								Expression_2 = ((Expression_) || (Fatom));

								bool F_1 = ((Fatom) || ((result_Stack[_ahead] == "37") && (Expression_) && (result_Stack[_ahead] == "38")));
								bool T_1 = (((Expression_) && (Opmul) && (F_1)) || (F_1));
								bool E_1 = (((Expression_) && (Opadd) && (T_1)) || (T_1));

								if (E_1)
								{
									S_Asgn = true;
								}
							}


						}
					}
				}
				#pragma endregion S_Asgn

				bool Stmt = ((S_Asgn) || (S_In) || (S_Out));
				if (Stmt)
				{
					for (int _ahead = i; _ahead < result_Stack.size(); _ahead++)
					{
						if ((result_Stack[_ahead] == "7 "))
						{
							Slist = true;
						}
					}
				}

				bool Pgm = false;

				//
				if (Opmul) { grammer_Stack.push_back("Opmul"); }
				if (Opadd) { grammer_Stack.push_back("Opadd");}
				if (Fatom) { grammer_Stack.push_back("Fatom"); }
				if (F_) { grammer_Stack.push_back("F"); }
				if (T_){ grammer_Stack.push_back("T"); }
				if (E_) { grammer_Stack.push_back("E"); }
				if (Elist2) { grammer_Stack.push_back("Elist2"); }
				if (Elist) { grammer_Stack.push_back("Elist"); }
				if (S_Out) { grammer_Stack.push_back("S_Out"); }
				if (S_In) { grammer_Stack.push_back("S_In"); }
				if (S_Asgn) { grammer_Stack.push_back("S_Asgn"); }
				if (Stmt) { grammer_Stack.push_back("Stmt"); }
				if (Slist) { grammer_Stack.push_back("Slist"); }
				if (Pgm) { grammer_Stack.push_back("Pgm"); }
			}


			ofstream myfile;
			string filename_ = "Output.txt" + index_Out;
			index_Out++;

			myfile.open(filename_);

			myfile << "Grammatical Analysis of Test Case" << endl;
			string _out_g = "";
			for (int index = 0; index < grammer_Stack.size(); index++)
			{
				_out_g += grammer_Stack[index] + ", ";
				myfile << _out_g << endl;
				cout << _out_g << endl;
			}

			myfile.close();

			result_Stack.clear();
			grammer_Stack.clear();
		}

	private:

		vector<string> Text_File;
		vector<string> id_string;

		vector<string> result_Stack;
		vector<string> Read_File;
		vector<string> grammer_Stack;

		int number_of_lines = 0;
		int index_Out = 0;
};
