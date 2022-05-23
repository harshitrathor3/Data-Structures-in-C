def Tower(n, frm, to, help):
    if n==1:
        ar[0]+=1
        print("Move Disk 1 from {} to {}".format(frm, to))
        return
    
    Tower(n-1, frm, help, to)
    print("Move Disk {} from {} to {}".format(n, frm, to))
    ar[0]+=1
    Tower(n-1, help, to, frm)


ar=[0]
n = int(input("Enter no of disks : "))
Tower(n, 'A', 'C', 'B')
print("Moves = ",ar[0])