import RegistrationPage from './pages/RegistrationPage';
import LoginPage from './pages/LoginPage';
import HomePage from './pages/HomePage';
import ProductPage from './pages/ProductPage';
import ProductDetailPage from './pages/ProductDetailPage';
import AboutPage from './pages/AboutPage';
import ContactPage from './pages/ContactPage';
// npm install react-router-dom
import { BrowserRouter, Routes, Route } from 'react-router-dom';
import ProtectedRoute from './components/routes/ProtectedRoute';
import CategoryProductPage from './pages/CategoryProductPage';

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path='/' element={<HomePage />} />
        {/* <Route path='/about' element={<AboutPage />} /> */}
        <Route path='/about' element={<ProtectedRoute Component={AboutPage} />} />
        <Route path='/products' element={<ProductPage />} />
        <Route path='/products/details/:id' element={<ProductDetailPage />} />
        <Route path='/login' element={<LoginPage />} />
        <Route path='/register' element={<RegistrationPage />} />
        <Route path='/contact' element={<ContactPage />} />
        <Route path='/categories/:id/products' element={<CategoryProductPage />} />
      </Routes>
    </BrowserRouter>
  );
}

export default App;
