import matplotlib.pyplot as plt
import numpy as np

def turn_to_num(string):
    try:
        return float(string)
    except:
        print(f"Error: {string}")
        return -1
    
def plot(x_list,y_list, x_axis_,title = 'Graph',scale = 'linear'):
    plt.plot(x_list,y_list)
    plt.xlabel(x_axis_)
    plt.ylabel('Time (s)')
    plt.title(title)
    plt.xscale(scale)
    plt.savefig(f'figures/{title}.png')
    plt.show()
    
f = open("results.txt", "r")
lines = f.readlines()
f.close()

N_TESTS = [10, 100, 1000, 10000, 100000]
PCTG_TESTS = [5,10,20,30,40,50]
gs_rc_index = lines.index("Graham Scan Random Clouds\n")
gw_rc_index = lines.index("Gift Wrapping Random Clouds\n")
gs_src_index = lines.index("Graham Scan Semi Random Clouds\n")
gw_src_index = lines.index("Gift Wrapping Semi Random Clouds\n")
graham_scan_rc = list(map(turn_to_num,lines[gs_rc_index+1:gw_rc_index]))
gift_wrapping_rc = list(map(turn_to_num,lines[gw_rc_index+1:gs_src_index]))

graham_scan_src = []
gift_wrapping_src = []
i = gs_src_index+1
for j in range(len(N_TESTS)):
    vec = []
    for k in range(len(PCTG_TESTS)):
        vec.append(turn_to_num(lines[i]))
        i += 1
    graham_scan_src.append(vec)
i += 1
for j in range(len(N_TESTS)):
    vec = []
    for k in range(len(PCTG_TESTS)):
        vec.append(turn_to_num(lines[i]))
        i += 1
    gift_wrapping_src.append(vec)


#plotting
graham_scan_rc = np.array(graham_scan_rc)
plot(N_TESTS,graham_scan_rc, 'Amount of points', 'Graham Scan Random Clouds', 'log')
gift_wrapping_rc = np.array(gift_wrapping_rc)
plot(N_TESTS,gift_wrapping_rc,'Amount of points', 'Gift Wrapping Random Clouds', 'log')
for i in range(len(N_TESTS)):
    graham_scan_src[i] = np.array(graham_scan_src[i])
    plot(PCTG_TESTS,graham_scan_src[i], 'Percentage',f'Graham Scan Semi Random Clouds {N_TESTS[i]} points')
    gift_wrapping_src[i] = np.array(gift_wrapping_src[i])
    plot(PCTG_TESTS,gift_wrapping_src[i],'Percentage',f'Gift Wrapping Semi Random Clouds {N_TESTS[i]} points')
