package org.drools.mydemo.app1;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class ExperimentDTO {

	private String id;

	private String landName;

	private String landId;

	private Double water;

	private ContentElements soilConstituents;

	private String recorder;

	private String weatherId;// ��������

	private Double dayTemperature;// ������¶ȡ�

	private Double nightTemperature;// ҹ�����¶ȡ�

	private Double airHumidity;// ����ʪ�ȣ�

	private Double soilTemperature;// �����¶ȡ�

	private Double soilHumidity;// ����ʪ�ȣ�

	private Double sunshine;// ����ʱ��h

	private Double lightIntensity;// ����ǿ��Lux

	private Double soilPH;// ����PHֵ

	private Double soilSalinity;// �����ζȣ�

	private Double co2;// CO2Ũ��ppm

	private Date createdDate;

	private List<String> result = new ArrayList<String>();

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getLandName() {
		return landName;
	}

	public void setLandName(String landName) {
		this.landName = landName;
	}

	public String getLandId() {
		return landId;
	}

	public void setLandId(String landId) {
		this.landId = landId;
	}

	public Double getWater() {
		return water;
	}

	public void setWater(Double water) {
		this.water = water;
	}

	public ContentElements getSoilConstituents() {
		return soilConstituents;
	}

	public void setSoilConstituents(ContentElements soilConstituents) {
		this.soilConstituents = soilConstituents;
	}

	public String getRecorder() {
		return recorder;
	}

	public void setRecorder(String recorder) {
		this.recorder = recorder;
	}

	public String getWeatherId() {
		return weatherId;
	}

	public void setWeatherId(String weatherId) {
		this.weatherId = weatherId;
	}

	public Double getDayTemperature() {
		return dayTemperature;
	}

	public void setDayTemperature(Double dayTemperature) {
		this.dayTemperature = dayTemperature;
	}

	public Double getNightTemperature() {
		return nightTemperature;
	}

	public void setNightTemperature(Double nightTemperature) {
		this.nightTemperature = nightTemperature;
	}

	public Double getAirHumidity() {
		return airHumidity;
	}

	public void setAirHumidity(Double airHumidity) {
		this.airHumidity = airHumidity;
	}

	public Double getSoilTemperature() {
		return soilTemperature;
	}

	public void setSoilTemperature(Double soilTemperature) {
		this.soilTemperature = soilTemperature;
	}

	public Double getSoilHumidity() {
		return soilHumidity;
	}

	public void setSoilHumidity(Double soilHumidity) {
		this.soilHumidity = soilHumidity;
	}

	public Double getSunshine() {
		return sunshine;
	}

	public void setSunshine(Double sunshine) {
		this.sunshine = sunshine;
	}

	public Double getLightIntensity() {
		return lightIntensity;
	}

	public void setLightIntensity(Double lightIntensity) {
		this.lightIntensity = lightIntensity;
	}

	public Double getSoilPH() {
		return soilPH;
	}

	public void setSoilPH(Double soilPH) {
		this.soilPH = soilPH;
	}

	public Double getSoilSalinity() {
		return soilSalinity;
	}

	public void setSoilSalinity(Double soilSalinity) {
		this.soilSalinity = soilSalinity;
	}

	public Double getCo2() {
		return co2;
	}

	public void setCo2(Double co2) {
		this.co2 = co2;
	}

	public Date getCreatedDate() {
		return createdDate;
	}

	public void setCreatedDate(Date createdDate) {
		this.createdDate = createdDate;
	}

	public List<String> getResult() {
		return result;
	}

	public void setResult(List<String> result) {
		this.result = result;
	}
	
	public void addResult(String result) {
		this.result.add(result);
	}

}
