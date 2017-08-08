#include <memory>
using std::shared_ptr; using std::make_shared;

struct destination;
struct connection;
connection connect(destination*);
void disconnect(connection);

void end_connection(connection *pc)
{
	disconnect(*pc);
}

void f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> spc(&c, end_connection);
}

void f2(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> spc(&c, [](connection *pc) {disconnect(*pc); });
}