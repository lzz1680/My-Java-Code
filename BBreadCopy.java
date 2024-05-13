import java.io.*;

public class BBreadCopy {
    public static void main(String[] args) throws Exception {
        InputStream is=new FileInputStream("D:\\steam\\steamapps\\workshop\\content\\431960\\2788691565\\preview.jpg");//读取的文件的地址下的文本
        OutputStream os =new FileOutputStream("D:\\Java-code2\\Project4\\src\\preview1.jpg");//输出也就是写出文件，并且放在缩写的目录下及其文档名
byte [] b=new byte[1024];
int len;
while((len= is.read(b))!=-1)
{
    os.write(b,0,len);
}

os.close();
is.close();
System.out.println("复制结束");
    }
}
