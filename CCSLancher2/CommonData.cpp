# include "CommonData.hpp"

void CommonData::loadGames(const FilePath& path) {
	games.setPath(path);
	games.loadGames();
}

void CommonData::next() {
	m_selected++;
	if (m_selected >= games.getList().size()) {
		m_selected = 0;
	}
}

void CommonData::prev() {
	m_selected--;
	if (m_selected < 0) {
		m_selected = games.getList().size() - 1;
	}
}

int CommonData::nextID(int cur) const {
	int id = m_selected + cur;
	int s = games.getList().size();
	id %= s; id += s; id %= s;
	return id;
}

int CommonData::prevID(int cur) const {
	int id = m_selected - cur;
	int s = games.getList().size();
	id %= s; id += s; id %= s;
	return id;
}

int CommonData::selected() const {
	return m_selected;
}