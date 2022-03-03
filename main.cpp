#include <iostream>
#include "table_const.h"
#include "table_var.h"
#include "lexeme.h"

int main() {

    string test_num;
    cout << "Enter test num: ";
    cin >> test_num;

    table_const keywords;

    keywords.read_file(test_num + "/keywords.txt");
    cout << "keywords.contains(\"main\") = " << keywords.contains("main") << endl;
    cout << "keywords.contains(\"float\") = " << keywords.contains("float") << endl;

    cout << "keywords.get_num(\"return\") = " << keywords.get_num("return") << endl;
    cout << "keywords.get_num(\"float\") = " << keywords.get_num("float") << endl;

    string elem;
    keywords.get_elem(0, elem);
    cout << "keywords.get_elem(0, elem): elem = " << elem << endl;


    table_var variables;

    table_var::place place1 = variables.add("ab");
    cout << "variables.add(\"ab\"): (i, j) = (" << place1.i << ", " << place1.j << ")" << endl;

    place1 = variables.add("abc");
    cout << "variables.add(\"abc\"): (i, j) = (" << place1.i << ", " << place1.j << ")" << endl;

    place1 = variables.add("bac");
    cout << "variables.add(\"bac\"): (i, j) = (" << place1.i << ", " << place1.j << ")" << endl;

    cout << "variables.contains(\"abc\") = " << variables.contains("abc") << endl;
    cout << "variables.contains(\"cab\") = " << variables.contains("cab") << endl;

    place1 = variables.find_place("ab");
    cout << "variables.find_place(\"ab\"): (i, j) = (" << place1.i << ", " << place1.j << ")" << endl;

    place1 = variables.find_place("b");
    cout << "variables.find_place(\"b\"): (i, j) = (" << place1.i << ", " << place1.j << ")" << endl;

    cout << "variables.get_hash(\"abc\") = " << variables.get_hash("abc") << endl;

    place1 = variables.find_place("ab");
    cout << "variables.get_lexeme(place1) = " <<
         "name: " << variables.get_lexeme(place1).name << " " <<
         "type: " << variables.get_lexeme(place1).type << " " <<
         "init: " << variables.get_lexeme(place1).init << " " <<
         endl;

    place1 = variables.find_place("abc");
    variables.set_type(place1, INT);
    cout << "type of the abc: " << variables.get_lexeme(place1).type << endl;

    place1 = variables.find_place("bac");
    variables.set_init(place1, true);
    cout << "init of the bac: " << variables.get_lexeme(place1).init << endl;


    return 0;
}
