package org.drools.applicant;

/**
 * ������������
 * 
 * @author lixl
 * @Date 2016��11��21������4:08:12
 */
public class SoilAnalysisData {

	private AgroType agroType;// ��������

	private String soilProfile;// ��������

	private String soilTexture;// �����ʵ�

	private String ploughLayer;// ������

	private SoilNutrient soilNutrient;// ��������

	private Float phValue; // PHֵ

	private Double moisture;// ��ˮ��

	private String landId;// �����ؿ�id

	public AgroType getAgroType() {
		return agroType;
	}

	public void setAgroType(AgroType agroType) {
		this.agroType = agroType;
	}

	public String getSoilProfile() {
		return soilProfile;
	}

	public void setSoilProfile(String soilProfile) {
		this.soilProfile = soilProfile;
	}

	public String getSoilTexture() {
		return soilTexture;
	}

	public void setSoilTexture(String soilTexture) {
		this.soilTexture = soilTexture;
	}

	public String getPloughLayer() {
		return ploughLayer;
	}

	public void setPloughLayer(String ploughLayer) {
		this.ploughLayer = ploughLayer;
	}

	public SoilNutrient getSoilNutrient() {
		return soilNutrient;
	}

	public void setSoilNutrient(SoilNutrient soilNutrient) {
		this.soilNutrient = soilNutrient;
	}

	public Float getPhValue() {
		return phValue;
	}

	public void setPhValue(Float phValue) {
		this.phValue = phValue;
	}

	public Double getMoisture() {
		return moisture;
	}

	public void setMoisture(Double moisture) {
		this.moisture = moisture;
	}

	public String getLandId() {
		return landId;
	}

	public void setLandId(String landId) {
		this.landId = landId;
	}

	public enum AgroType {
		SANDY_SOIL, // ɰ����
		CLAY_SOIL, // �����
		LOAMY_SOIL// ����
	}

	public enum SoilNutrient {
		GEIN, // �����л���
		NITROGEN, // ȫ��
		PHOSPHORUS, // ȫ��
		POTASSIUM, // ȫ��
		AVAILABLE_NITROGEN, // ��⵪
		RAPID_AVAILABLE_PHOSPHORUS, // ��Ч��
		RAPID_AVAILABLE_POTASSIUM // ��Ч��
	}
}
