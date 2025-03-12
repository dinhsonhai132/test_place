#include "MercuryEngine.cpp"

int main() {
    MercuryEngine_ _engine = createMercuryEngine();
    _engine.push_float(2.000000);
    _engine.store_global("x");
    _engine.push_float(3.000000);
    _engine.store_global("y");
    _engine.load_global("print");
    _engine.load_global("x");
    _engine.load_global("y");
    _engine.binary_plus();
    _engine.call_function();
    return 0;
}

