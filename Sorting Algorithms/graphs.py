import matplotlib.pyplot as plt

def plot_graph(x,y1, y2, title, x_label, y_label):
    plt.plot(x, y1)
    plt.plot(x,y2)
    plt.title(title)
    plt.xlabel(x_label)
    plt.ylabel(y_label)
    plt.show()

def main():
    arrayLengths = [3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49]
    recursiveTimes = [0,0,1,1,1,2,2,2,3,3,3,4,4,5,5,5,6,6,7,7,8,8,8,9]
    iterativeTimes = [6,6,7,9,12,13,16,19,21,23,26,28,28,33,39,35,37,44,44,48,54,54,50,56]
    plot_graph(arrayLengths, recursiveTimes, iterativeTimes, "Recursive vs Iterative", "Array Length", "Time (ms)")

if __name__ == "__main__":
    main()