def ChiSo(cannang, chieucao):
    return cannang/(chieucao**2)

def main():
    cannang = float(input("nhap can nang: "))
    chieucao = float(input("nhap chieu cao: "))
    rs = ChiSo(cannang, chieucao)
    print(f"{rs: .1f}")
    if rs < 18.5:
        print("Gay")
    elif rs < 25:
        print("Bthg")
    elif rs < 30:
        print("Thua can")
    else:
        print("Beo phi")
main()
