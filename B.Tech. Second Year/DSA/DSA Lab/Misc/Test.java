class Test {
    public static String multiplyStrings(String s1, String s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        int a = s1.charAt(0) == '-' ? -1 : 0;
        int b = s2.charAt(0) == '-' ? -1 : 0;
        int[] res = new int[l1 + l2];
        int pf = 0;
        for (int i = l2 - 1; i >= 0; i--) {
            int k = res.length - 1 - pf;
            if (s2.charAt(i) != '-') {
                int inum = s2.charAt(i) - '0';
                int j = l1 - 1;
                int carry = 0;
                while (j >= 0 || carry != 0) {
                    if (s1.charAt(j) != '-') {
                        int jnum = j >= 0 ? s1.charAt(j) - '0' : 0;
                        int prod = inum * jnum + carry + res[k];
                        res[k] = prod % 10;
                        carry = prod / 10;
                        k--;
                    }
                    j--;
                }
                pf++;
            }
        }
        int flag = 0;
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < l1 + l2; i++) {
            while (i < l1 + l2 && flag == 0 && res[i] == 0) {
                i++;
            }
            flag = 1;
            if (i < l1 + l2)
                result.append(res[i]);
        }
        String str = result.toString();
        if (a < 0 && b >= 0 || a >= 0 && b < 0) {
            str = '-' + str;
        }
        return str.length() == 0 ? "0" : str;
    }

    public static void main(String[] args) {
        String s1 = "9";
        String s2 = "2433";

        String product = multiplyStrings(s1, s2);
        System.out.println(product);
    }
}