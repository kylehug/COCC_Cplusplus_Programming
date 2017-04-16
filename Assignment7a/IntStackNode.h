class IntStackNode
{
	public:

		// Variable Declarations
		int value;
		IntStackNode *next;

		// Constructors
		IntStackNode();
		IntStackNode(int value);
		IntStackNode(int value, IntStackNode *next);

		// Destructor
		~IntStackNode();
};