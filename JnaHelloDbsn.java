import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Platform;
 
/** Simple example of native library declaration and usage. */
public class JnaHelloDbsn {



    public interface DbsnLibrary extends Library {
        DbsnLibrary INSTANCE = (DbsnLibrary) Native.loadLibrary("dbsn", DbsnLibrary.class);
        int createDBSN(String fil_name);
        int closeDBSN(int dbhadr);
        int openDBSN(String fil_name);
        int addFragm(int dbhadr, String fragm, int sys_tag, int tag);    
        int flushDBSN(int  dbhadr); 

        int setNom(int dbhadr, int new_nom);
        int getFragm(int dbhadr, byte[] fragm, int bufsize);
    }

    public static void main(String[] args) {

        String myLibraryPath = System.getProperty("user.dir");//or another absolute or relative path        
        System.out.println(myLibraryPath);
        System.setProperty("java.library.path", myLibraryPath);
        
        int dh = DbsnLibrary.INSTANCE.openDBSN("TestDBSN");
        System.out.printf("Result of openDBSN: %d \n", dh);

        int res;
        if (dh < 0) {
            res = DbsnLibrary.INSTANCE.createDBSN("TestDBSN");
            System.out.printf("Result of createDBSN: %d \n", dh);
            dh = DbsnLibrary.INSTANCE.openDBSN("TestDBSN");
            System.out.printf("Result of openDBSN: %d \n", dh);
        }

        // System.out.printf("Result of addFrag: %d \n", askAndSaveRecord(dh));


        System.out.println("Result of getFragm: "+ getRecord(dh, 5));



        res = DbsnLibrary.INSTANCE.flushDBSN(dh); 
        System.out.printf("Result of flushDBSN: %d \n", res);

        res = DbsnLibrary.INSTANCE.closeDBSN(dh);
        System.out.printf("Result of closeDBSN: %d \n", res);
    }


    public static int askAndSaveRecord(int dbhadr) 
    {
        String fragmStr = "Hello, World!";
        int res = DbsnLibrary.INSTANCE.addFragm(dbhadr, fragmStr, 0, 0);
        System.out.printf("Result of addFrag: %d \n", res);
        return res;
    }

    public static String getRecord(int dbhadr, int new_nom) 
    {
        int chunkSize = 32567;
        byte[] fragm  = new byte[chunkSize];
        DbsnLibrary.INSTANCE.setNom(dbhadr, new_nom);
        DbsnLibrary.INSTANCE.getFragm(dbhadr, fragm, fragm.length);
        String fragmStr = new String(fragm).trim();
        return fragmStr;
    }
}