#include <iostream>
#include <Table.h>
#include <easylink/data/Database.h>
#include <easylink/utils/Executor.h>

using namespace easylink;

int main()
{
#define SECTION_12
#ifndef SECTION_1
#define SECTION_1
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
#endif // SECTION_1
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
    return 0;
}
