import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
/**
 * Created by user on 12/23/2016.
 */
public class CreateAccount implements ActionListener {
    JFrame frame;
    JLabel FNameLb, LNameLb, BirthDateLb, PhoneNumberLb, EmailLb, UserNameLb, PasswordLb, ReEnter_PasswordLb, CountryLb;
    JTextField FNameTf, LNameTf, PhoneNumberTf, EmailTf, UserNameTf, CountryTf;
    JComboBox DayJc, MonthJc, YearJc;
    JPasswordField PasswordTf, ReEnterPasswordTf;
    JButton button;
    Container c;


    public CreateAccount() {
        //Frame create;
        frame = new JFrame("CreateAccount");
        frame.setVisible(true);
       // frame.setDefaultCloseOperation(JFrame.D);
        frame.setBounds(50, 50, 800, 500);

        c = frame.getContentPane();
        c.setLayout(null);

        //Code for Jlabel;
        FNameLb = new JLabel("First Name :");
        LNameLb = new JLabel("Last Name :");
        BirthDateLb = new JLabel("Birth Date :");
        PhoneNumberLb = new JLabel("Phone Number :");
        EmailLb = new JLabel("Email Address :");
        UserNameLb = new JLabel("User Name :");
        PasswordLb = new JLabel("Password :");
        ReEnter_PasswordLb = new JLabel("Re-enter password :");
        CountryLb = new JLabel("Country :");

        //Code For Set JLabel;
        FNameLb.setBounds(100, 50, 150, 20);
        LNameLb.setBounds(100, 90, 150, 20);
        BirthDateLb.setBounds(100, 130, 150, 20);
        PhoneNumberLb.setBounds(100, 170, 150, 20);
        EmailLb.setBounds(100, 210, 150, 20);
        UserNameLb.setBounds(100, 250, 200, 20);
        PasswordLb.setBounds(100, 290, 200, 20);
        ReEnter_PasswordLb.setBounds(100, 330, 200, 20);
        CountryLb.setBounds(100, 370, 200, 20);

        //Code for JTextField;
        FNameTf = new JTextField();
        LNameTf = new JTextField();
        String[] Day_arr = new String[31];
        for (int i = 1; i <= Day_arr.length; i++) {
            Day_arr[i - 1] = Integer.toString(i);
        }
        DayJc = new JComboBox(Day_arr);

        String[] month_arr = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        MonthJc = new JComboBox(month_arr);
        String[] year_arr = new String[101];
        for (int i = 1950; i <= 2050; i++) {
            year_arr[i - 1950] = Integer.toString(i);
        }
        YearJc = new JComboBox(year_arr);
        PhoneNumberTf = new JTextField();
        EmailTf = new JTextField();
        UserNameTf = new JTextField();
        PasswordTf = new JPasswordField();
        ReEnterPasswordTf = new JPasswordField();
        CountryTf = new JTextField();

        //Code For SetBounds of JTextField;
        FNameTf.setBounds(270, 50, 150, 20);
        LNameTf.setBounds(270, 90, 150, 20);
        DayJc.setBounds(270, 130, 50, 20);
        MonthJc.setBounds(340, 130, 80, 20);
        YearJc.setBounds(440, 130, 100, 20);
        PhoneNumberTf.setBounds(270, 170, 150, 20);
        EmailTf.setBounds(270, 210, 150, 20);
        UserNameTf.setBounds(270, 250, 150, 20);
        PasswordTf.setBounds(270, 290, 150, 20);
        ReEnterPasswordTf.setBounds(270, 330, 150, 20);
        CountryTf.setBounds(270, 370, 150, 20);

        button = new JButton("Sign Up");
        button.setBounds(270, 420, 80, 30);

        //Code for Add JLabel & JTextField;
        c.add(FNameLb);
        c.add(FNameTf);
        c.add(LNameLb);
        c.add(LNameTf);
        c.add(BirthDateLb);
        c.add(DayJc);
        c.add(MonthJc);
        c.add(YearJc);
        c.add(PhoneNumberLb);
        c.add(PhoneNumberTf);
        c.add(EmailLb);
        c.add(EmailTf);
        c.add(UserNameLb);
        c.add(UserNameTf);
        c.add(PasswordLb);
        c.add(PasswordTf);
        c.add(ReEnter_PasswordLb);
        c.add(ReEnterPasswordTf);
        c.add(button);
        c.add(CountryLb);
        c.add(CountryTf);

        button.addActionListener(this);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we)
            {
                new Login();
            }
        });


    }//End create account constructor;

    @Override
    public void actionPerformed(ActionEvent e) {

        if (e.getSource() == button) {
            //convert passWord in String;
            char[] pass = PasswordTf.getPassword();
            String passWord = new String(pass);
            //convert repassword in string;
            char[] repass = ReEnterPasswordTf.getPassword();
            String reEnterPassWord = new String(repass);

            if (!(FNameTf.getText().isEmpty() || LNameTf.getText().isEmpty() || PhoneNumberTf.getText().isEmpty() || EmailTf.getText().isEmpty() || UserNameTf.getText().isEmpty() || CountryTf.getText().isEmpty() || passWord.equals("") || reEnterPassWord.equals("")))
            {
                int UFlag = 0, PFlag = 0;
                if (passWord.equals(reEnterPassWord)) {
                    try {
                        BufferedReader br = new BufferedReader(new FileReader("text/signUp.txt"));
                        String line;
                        while((line = br.readLine())!= null) {
                            String sp[] = line.split("\t");
                            if (sp[0].equals(UserNameTf.getText())) {
                                UFlag = 1;
                                break;
                            }
                            if (sp[3].equals(PhoneNumberTf.getText())) {
                                PFlag = 1;
                                break;
                            }
                        }
                        br.close();

                    } catch (Exception e1) {
                    }
                    if (UFlag == 0 && PFlag == 0) {
                        try {

                            FileWriter fw = new FileWriter("text/signUp.txt", true);
                            BufferedWriter bw = new BufferedWriter(fw);
                            String info = UserNameTf.getText() + "\t" + passWord + "\t" + EmailTf.getText() + "\t" + PhoneNumberTf.getText() + "\t" + FNameTf.getText() + "\t" + LNameTf.getText() + "\t" + DayJc.getSelectedItem() + "/" + MonthJc.getSelectedItem() + "/" + YearJc.getSelectedItem();
                            bw.write(info);
                            bw.write("\n");
                            bw.close();
                            frame.setVisible(false);
                            JOptionPane.showMessageDialog(null,"Your acount successfully created","messege",JOptionPane.INFORMATION_MESSAGE);
                            Login logClass = new Login();
                        } catch (Exception ec) {
                        }
                    } else {
                        //System.out.println("error show for repeat username && phone number");
                        if(UFlag==1){
                            JOptionPane.showMessageDialog(null,"Your user name is already used.Please Change the user name","Messege",JOptionPane.ERROR_MESSAGE);
                            UserNameTf.setText("");
                        }
                        else if(PFlag == 1){
                            JOptionPane.showMessageDialog(null,"Your phone number is already used.Please Change the phone number","Messege",JOptionPane.ERROR_MESSAGE);
                            PhoneNumberTf.setText("");
                        }
                    }//end of  repeat username && phone number conditon else
                } else {
                   JOptionPane.showMessageDialog(null ,"password and re-enter password don,t match","Messege",JOptionPane.ERROR_MESSAGE);

                   PasswordTf.setText("");
                   ReEnterPasswordTf.setText("");
                }


            } else {
                JOptionPane.showMessageDialog(null ,"Fillup Your Field","Messege",JOptionPane.ERROR_MESSAGE);


            }//end of text field;

        }
    }
}
