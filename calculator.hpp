class Calculator {
    public:
        static float add(float a, float b) {
            return a + b;
        }

        static float subtract(float a, float b) {
            return a - b;
        }

        static float multiply(float a, float b) {
            return a * b;
        }

        static float divide(float a, float b) {
            return is_division_by_zero(b) ? -1 : a / b;
        }

        static void initializeOperations() {
            operations['+'] = add;
            operations['-'] = subtract;
            operations['*'] = multiply;
            operations['/'] = divide;
        }

        static float (*operations[256])(float, float);

    private:
        static bool is_division_by_zero(float b) {
            return b == 0;
        }
};