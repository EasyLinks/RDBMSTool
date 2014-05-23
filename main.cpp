#include <iostream>
#include <Table.h>
#include <easylink/data/Database.h>
#include <easylink/utils/Executor.h>
#include <easylink/utils/Observer.h>
#include <easylink/utils/Arguments.h>

using namespace easylink;

int main()
{
#define SECTION_1
#ifndef SECTION_1
    data::Table table = data::Table();
    table.addField<int>("id");
    table.addField<std::string>("name");
    table.addField<std::string>("commentary");
    table.addField<float>("cash");
    table.writeBuffer<int>("id", 0);
    table.writeBuffer<std::string>("name", "Joseph Adams");
    table.writeBuffer<std::string>("commentary", "No commentary here");
    table.writeBuffer<float>("cash", 1.25);
    table.flush();
    table.writeBuffer<int>("id", 7);
    table.writeBuffer<std::string>("name", "Mr. Bean");
    table.writeBuffer<std::string>("commentary", "WTF, MAN?!");
    table.writeBuffer<float>("cash", 666.66);
    table.flush();
    std::cout << "name: " << table.get("name", 0).toString() << std::endl;
    table.update("commentary", 1, std::string("Inapropriate content"));
    std::cout << "name: " << table.get("name", 1).toString() << std::endl;
    data::Database newDB = data::Database();
    newDB.createTable("employees");
    newDB.createField<int>("employees", "id");
    newDB.createField<std::string>("employees", "first_name");
    newDB.createField<std::string>("employees", "second_name");
    newDB.createField<std::string>("employees", "middle_name");
    newDB.writeBuffer<int>("employees", "id", 7);
    newDB.writeBuffer<std::string>("employees", "first_name", "Konstantin");
    newDB.writeBuffer<std::string>("employees", "second_name", "Baluev");
    newDB.writeBuffer<std::string>("employees", "middle_name", "Jurievich");
    newDB.flush("employees");
    newDB.writeBuffer<int>("employees", "id", 9);
    newDB.writeBuffer<std::string>("employees", "first_name", "Vladimir");
    newDB.writeBuffer<std::string>("employees", "second_name", "Filipovsky");
    newDB.writeBuffer<std::string>("employees", "middle_name", "Mikhailovich");
    newDB.flush("employees");
    int a;
    std::cin >> a;
    std::cout << "Inserted \"id\" value is: " << newDB.getString("employees", "id", a) << std::endl;
    std::cout << "Inserted \"first_name\" value is: " << newDB.getString("employees", "first_name", a) << std::endl;
    std::cout << "Inserted \"second_name\" value is: " << newDB.getString("employees", "second_name", a) << std::endl;
    std::cout << "Inserted \"middle_name\" value is: " << newDB.getString("employees", "middle_name", a) << std::endl;
#endif // SECTION_1
//#define SECTION_2
#ifndef SECTION_2
    data::ContainerA A = data::ContainerA(std::string("Hello, world"));
    data::ContainerA B = data::ContainerA(std::string("Hello, world!"));
    std::cout << "STRING" << '\n'
              << "A = " << A.toString() << " B = " << B.toString() << '\n'
              << "A == B: " << (A == B) << '\n'
              << "A != B: " << (A != B) << '\n'
              << "A < B:  " << (A < B) << '\n'
              << "B < A:  " << (B < A) << '\n'
              << "A > B:  " << (A > B) << '\n'
              << "B > A:  " << (B > A) << '\n'
              << "A <= B:  " << (A <= B) << '\n'
              << "A >= B:  " << (A >= B) << '\n';
    A.setData(int(1));
    B.setData(int(2));
    std::cout << "INT" << '\n'
              << "A = " << A.toString() << " B = " << B.toString() << '\n'
              << "A == B: " << (A == B) << '\n'
              << "A != B: " << (A != B) << '\n'
              << "A < B:  " << (A < B) << '\n'
              << "B < A:  " << (B < A) << '\n'
              << "A > B:  " << (A > B) << '\n'
              << "B > A:  " << (B > A) << '\n'
              << "A <= B:  " << (A <= B) << '\n'
              << "A >= B:  " << (A >= B) << '\n';
    A.setData(float(1));
    B.setData(float(2));
    std::cout << "FLOAT" << '\n'
              << "A = " << A.toString() << " B = " << B.toString() << '\n'
              << "A == B: " << (A == B) << '\n'
              << "A != B: " << (A != B) << '\n'
              << "A < B:  " << (A < B) << '\n'
              << "B < A:  " << (B < A) << '\n'
              << "A > B:  " << (A > B) << '\n'
              << "B > A:  " << (B > A) << '\n'
              << "A <= B:  " << (A <= B) << '\n'
              << "A >= B:  " << (A >= B) << '\n';

    /*utils::Arguments properties = utils::Arguments();
    properties.set<std::string>("counter", "id");
    B.assign(A);
    utils::Arguments args = utils::Arguments();
    utils::Observer beholder = utils::Observer();
    beholder.createDatabase("mydb");
    std::cout << "Database created." << std::endl;
    beholder.connect("mydb", args);
    std::cout << "Connected to database." << std::endl;
    data::Database* mydb = beholder.getDatabase();
    std::cout << "Link obtained." << std::endl;
    mydb->createTable("users");
    std::cout << "Table created." << std::endl;
    beholder.selectTable("users");
    std::cout << "Table selected." << std::endl;
    data::Table* users = beholder.getTable();
    std::cout << "Table link obtained." << std::endl;
    users->addField<int>("id");
    users->addField<std::string>("first_name");
    users->addField<std::string>("second_name");
    users->addField<std::string>("middle_name");
    std::cout << "Fields added." << std::endl;
    users->writeBuffer<int>("id", 777);
    users->writeBuffer<std::string>("first_name", "Konstantin");
    users->writeBuffer<std::string>("second_name", "Baluev");
    users->writeBuffer<std::string>("middle_name", "Jurievich");
    std::cout << "Buffer written." << std::endl;
    users->flush();
    data::Entry* concrete = users->getLine(users->length() - 1);
    std::cout << "Flushed." << std::endl;
    std::cout << "id: " << concrete->toString(users->getIndex("id"))
              << " | first_name: " << concrete->toString(users->getIndex("first_name"))
              << " | second_name: " << concrete->toString(users->getIndex("second_name"))
              << " | middle_name: " << concrete->toString(users->getIndex("middle_name")) << std::endl;*/
#endif // SECTION_2
    return 0;
}
