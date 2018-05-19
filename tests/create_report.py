import os
import sys

import pandas as pd
import matplotlib.pyplot as plt


input_file=sys.argv[1]
output_folder=os.path.dirname(input_file)


data=pd.read_csv(input_file)


#trig:
def create_image(fun_names, file_name):

    for name in fun_names:
        vals=data.loc[data['N'] == name]
        plt.plot(vals.PERM_ID, vals.CNT, label=name)
    plt.legend()
    plt.xlabel('permutation id')
    plt.ylabel('count')
    axes = plt.gca()
    axes.set_ylim([0,11000])
    #plt.show()
    plt.savefig(file_name)
    plt.close()



create_image(list(range(3,10)), os.path.join(output_folder,'distributions.png'))

