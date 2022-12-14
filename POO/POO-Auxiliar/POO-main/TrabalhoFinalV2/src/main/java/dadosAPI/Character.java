package dadosAPI;

public class Character {

    private Integer id;
    private Integer char_id;
    private String name;
    private String birthday;
    private String occupation;
    private String img;
    private String status;
    private String nickname;
    private String appearance;
    private String portrayed;
    private String category;
    private String better_call_saul_appearance;

    public Character(){}

    public Character(Integer id,Integer char_id, String name, String birthday, String occupation, String img, String status, String nickname, String appearance, String portrayed, String category, String better_call_saul_appearance) {

    }

    @Override
    public String toString() {
        return "ID: " + char_id + "\nNome: " + name + "\nAniversario: " + birthday+ "\nOcupacao: " + occupation + "\nFoto: " + img + "\nStatus: " + status + "\nCodinome: " + nickname + "\nAparicoes: " + appearance + "\nInterpretado(a):" + portrayed + "\nCategoria: " + category + "\nAparicoes em Better Call Saul: " + better_call_saul_appearance + "\n";
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getChar_id() {
        return char_id;
    }

    public void setChar_id(Integer char_id) {
        this.char_id = char_id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getBirthday() {
        return birthday;
    }

    public void setBirthday(String birthday) {
        this.birthday = birthday;
    }

    public String getOccupation() {
        return occupation;
    }

    public void setOccupation(String occupation) {
        this.occupation = occupation;
    }

    public String getImg() {
        return img;
    }

    public void setImg(String img) {
        this.img = img;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public String getNickname() {
        return nickname;
    }

    public void setNickname(String nickname) {
        this.nickname = nickname;
    }

    public String getAppearance() {
        return appearance;
    }

    public void setAppearance(String appearance) {
        this.appearance = appearance;
    }

    public String getPortrayed() {
        return portrayed;
    }

    public void setPortrayed(String portrayed) {
        this.portrayed = portrayed;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public String getBetter_call_saul_appearance() {
        return better_call_saul_appearance;
    }

    public void setBetter_call_saul_appearance(String better_call_saul_appearance) {
        this.better_call_saul_appearance = better_call_saul_appearance;
    }
}
