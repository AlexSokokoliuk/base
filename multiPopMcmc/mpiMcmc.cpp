#include <stdexcept>

#include "MpiMcmcApplication.hpp"

using std::cerr;
using std::endl;
using std::exception;

int main (int argc, char *argv[])
{
    Settings settings;

    try
    {
        // Setup settings
        settings.loadSettings (argc, argv);

        if (settings.development)
        {
            cout << "Bayesian Analysis of Stellar Evolution (Multiple Populations)" << endl;

            if (settings.seed == std::numeric_limits<uint32_t>::max())
            {
                srand(std::time(0));
                settings.seed = rand();

                cout << "Seed: " << settings.seed << endl;
            }

            MpiMcmcApplication master(settings);

            return master.run();
        }
        else
        {
            cerr << "multiPropMcmc is still under development\n";
            return -1;
        }
    }
    catch (exception &e)
    {
        cerr << "\nException: " << e.what() << endl;
        return -1;
    }

}
