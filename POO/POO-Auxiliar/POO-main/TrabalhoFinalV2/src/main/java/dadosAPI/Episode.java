package dadosAPI;

import java.util.Arrays;

public class Episode {

    private Integer id;
    private Integer episode_id;
    private String title;
    private String season;
    private String episode;
    private String air_date;
    private String characters;
    private String series;

    public Episode(Integer id,Integer episode_id, String title, String season, String episode, String air_date, String characters, String series) {

    }
    public Episode(){}

    public String toString() {
        return "ID Episodio: " + episode_id + "\nTitulo: " + title + "\nTemporada: " + season + "\nEpisodio: " + episode + "\nData transmitida: " + air_date + "\nPersonagens: " + characters + "\nSerie: " + series + "\n";
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getEpisode_id() {
        return episode_id;
    }

    public void setEpisode_id(Integer episode_id) {
        this.episode_id = episode_id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getSeason() {
        return season;
    }

    public void setSeason(String season) {
        this.season = season;
    }

    public String getEpisode() {
        return episode;
    }

    public void setEpisode(String episode) {
        this.episode = episode;
    }

    public String getAir_date() {
        return air_date;
    }

    public void setAir_date(String air_date) {
        this.air_date = air_date;
    }

    public String getCharacters() {
        return characters;
    }

    public void setCharacters(String characters) {
        this.characters = characters;
    }

    public String getSeries() {
        return series;
    }

    public void setSeries(String series) {
        this.series = series;
    }
}
