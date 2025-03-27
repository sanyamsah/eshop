import Navbar from "../../components/Navbar";
import { Link } from "react-router-dom";

const ContactPage = () => {
    return (
        <>
            <Navbar />
            <div className="container py-5"
                style={{ backgroundColor: '#F2EFE7', minHeight: 'calc(100vh - 56px)' }}
            >
                <div className="row justify-content-center">
                    <div className="col-lg-8">
                        <div className="bg-white p-4 p-md-5 rounded shadow-sm">
                            <h2 className="text-center mb-4" style={{ color: '#006A71' }}>Contact Us</h2>

                            <form>
                                <div className="mb-4">
                                    <label className="form-label" style={{ color: '#006A71' }}>Name</label>
                                    <input
                                        type="text"
                                        className="form-control"
                                        placeholder="Enter your name"
                                        style={{ borderColor: '#006A71' }}
                                        required
                                    />
                                </div>

                                <div className="mb-4">
                                    <label className="form-label" style={{ color: '#006A71' }}>Email</label>
                                    <input
                                        type="email"
                                        className="form-control"
                                        placeholder="Enter your email"
                                        style={{ borderColor: '#006A71' }}
                                        required
                                    />
                                </div>

                                <div className="mb-4">
                                    <label className="form-label" style={{ color: '#006A71' }}>Message</label>
                                    <textarea
                                        className="form-control"
                                        rows="5"
                                        placeholder="Your message..."
                                        style={{ borderColor: '#006A71' }}
                                        required
                                    ></textarea>
                                </div>

                                <div className="d-grid gap-3">
                                    <button
                                        type="submit"
                                        className="btn btn-lg"
                                        style={{
                                            backgroundColor: '#006A71',
                                            color: 'white',
                                            border: 'none'
                                        }}
                                        onMouseEnter={(e) => e.target.style.backgroundColor = '#48A6A7'}
                                        onMouseLeave={(e) => e.target.style.backgroundColor = '#006A71'}
                                    >
                                        Send Message
                                    </button>

                                    <Link
                                        to="/"
                                        className="btn btn-outline-secondary btn-lg"
                                        style={{
                                            borderColor: '#006A71',
                                            color: '#006A71'
                                        }}
                                        onMouseEnter={(e) => {
                                            e.target.style.backgroundColor = '#F2EFE7';
                                        }}
                                        onMouseLeave={(e) => {
                                            e.target.style.backgroundColor = 'white';
                                        }}
                                    >
                                        Back to Home
                                    </Link>
                                </div>
                            </form>
                        </div>
                    </div>
                </div>
            </div>
        </>
    );
}

export default ContactPage;